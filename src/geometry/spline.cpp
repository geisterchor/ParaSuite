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

void Spline::calculateSpline() {
    const unsigned int n = points.size();
    assert (n >= 2);
    /*
    a = mat(n,3);
    b = mat(n,3);
    c = mat(n,3);
    d = mat(n,3);
    */
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;
    
    
    const unsigned int lgs_size = 4*(n-1);
    for(unsigned int p=0; p<3; p++) {
        SparseMatrix<double> M(lgs_size,lgs_size);
        VectorXd rhs(lgs_size);
        rhs.fill(0);
        
        for(unsigned int i=0; i<n; i++)
            cout << points[i] << endl;
        
        for(unsigned int i=0; i<n-1; i++) {
            M.insert(4*i + 0, 4*i + a) = 1;
            rhs(4*i + 0) = points[i][p];
            
            M.insert(4*i + 1, 4*i + a) = 1;
            M.insert(4*i + 1, 4*i + b) = 1;
            M.insert(4*i + 1, 4*i + c) = 1;
            M.insert(4*i + 1, 4*i + d) = 1;
            rhs(4*i + 1) = points[i+1][p];
            
            if(i<n-2) {
                M.insert(4*i + 2, 4*i + b) = 1;
                M.insert(4*i + 2, 4*i + c) = 2;
                M.insert(4*i + 2, 4*i + d) = 3;
                M.insert(4*i + 2, 4*(i+1) + b) = -1;
            }
            else {
                M.insert(4*i + 2, c) = 1;  // 2nd derivative at first knot = 0
            }
            rhs(4*i + 2) = 0;
        
            M.insert(4*i + 3, 4*i + c) = 1;
            M.insert(4*i + 3, 4*i + d) = 3;
            if(i<n-2) {
                M.insert(4*i + 3, 4*(i+1) + c) = -1;
            }
                rhs(4*i + 3) = 0;
        }
        
        // packaging the 2nd derivative in a nice row with a diagonal element
        M.coeffRef(4*(n-1)-2, 4*(n-2) + 0) += M.coeffRef(4*(n-1)-3, 4*(n-2) + 0);
        M.coeffRef(4*(n-1)-2, 4*(n-2) + 1) += M.coeffRef(4*(n-1)-3, 4*(n-2) + 1);
        M.coeffRef(4*(n-1)-2, 4*(n-2) + 2) += M.coeffRef(4*(n-1)-3, 4*(n-2) + 2);
        M.coeffRef(4*(n-1)-2, 4*(n-2) + 3) += M.coeffRef(4*(n-1)-3, 4*(n-2) + 3);
        rhs(4*(n-1)-2) = rhs(4*(n-1)-2) + rhs(4*(n-1)-3);
        
        cout << "M:" << endl << MatrixXd(M) << endl << endl;  
                
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
        
            
        cout << "RHS:" << endl << rhs << endl << endl;    
        cout << "x:" << endl << x << endl << endl;        
        cout << "Residuum:" << (M*x - rhs).norm() << endl << endl;
    }    
}
