/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#include "spline.h"

#include <assert.h>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/IterativeLinearSolvers>


using namespace std;
using namespace parasuite::geometry;

/**
 * \brief Calculates Spline coefficients
 * 
 * calculates coefficients for three 1d splines that
 * will be merged to a 3d spline afterwards.
 * The 1d cubic spline algorithm is described here: 
 * http://mathworld.wolfram.com/CubicSpline.html
 */
void Spline::calculateSpline() {
    n = points.size();
    assert (n >= 2);
    
    a = MatrixXd(n,3);
    b = MatrixXd(n,3);
    c = MatrixXd(n,3);
    d = MatrixXd(n,3);
    
    for(unsigned int p=0; p<3; p++) {
        SparseMatrix<double> M(n,n);
        VectorXd rhs(n);
        
        M.insert(0,0) = 2;
        M.insert(0,1) = 1;
        
        rhs(0) = 3*(points[1][p] - points[0][p]);
        for (unsigned int i=1; i<n-1; i++) {
            M.insert(i,i-1) = 1;
            M.insert(i,i)   = 4;
            M.insert(i,i+1) = 1;
            rhs(i) = 3*(points[i+1][p] - points[i-1][p]);
        }
        M.insert(n-1,n-2) = 1;
        M.insert(n-1,n-1) = 2;
        rhs(n-1) = 3*(points[n-1][p] - points[n-2][p]);
        
        BiCGSTAB<SparseMatrix<double>, IncompleteLUT<double>> solver;
        solver.preconditioner().setFillfactor(7);
        //solver.setMaxIterations(100);
        //solver.setTolerance(1e-8);
        solver.compute(M);
        if(solver.info()!=Success) {
          cout << "solver.compute(M) failed" << endl;
          return;
        }
        VectorXd x = solver.solve(rhs);
        
        for(unsigned int i=0; i<n-1; i++) {
            a(i,p) = points[i][p];
            b(i,p) = x[i];
            c(i,p) = 3*(points[i+1][p]-points[i][p]) - 2*x[i]-x[i+1];
            d(i,p) = 2*(points[i][p]-points[i+1][p]) + x[i] + x[i+1];
        }
        
        #ifdef DEBUG
        cout << "M:" << endl << MatrixXd(M) << endl << endl;  
        cout << "RHS:" << endl << rhs << endl << endl;    
        cout << "x:" << endl << x << endl << endl;        
        cout << "Residuum:" << (M*x - rhs).norm() << endl << endl;
        #endif
    }    
}

Vector3d Spline::getPoint(double tau) {
    assert ( tau >= 0 );
    assert ( tau <= 1 );
    
    double t = tau * (n-1);
    
    unsigned int i = floor(t);
    if (i==n-1)
        i=n-2;
    
    #ifdef DEBUG
    cout << "tau="<<tau << " t="<<t << " i="<<i << " n="<<n<<endl;
    #endif
    
    Vector3d res;
    for(int p = 0; p<3; p++) {
        res[p] = a(i,p) + b(i,p)*(t-i) + c(i,p)*(t-i)*(t-i) + d(i,p)*(t-i)*(t-i)*(t-i);
    }
    return res;
}


