/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#include<fstream>

#include <iostream>
#include <sstream>

#include <Eigen/Dense>

#include "geometry/airfoil.h"
#include "geometry/spline.h"


using namespace std;
using namespace Eigen;
using namespace parasuite::geometry;


void writeToCSVfile(string name, MatrixXd matrix)
{
	ofstream file(name.c_str());

	for(int  i = 0; i < matrix.rows(); i++) {
		for(int j = 0; j < matrix.cols(); j++) {
			file << matrix(i,j);
			if(j+1 < matrix.cols()){
				file << ',';
			}
		}
		file << '\n';
	}
}

  
int main(void) {    
    cout << "Hallo Welt!" << endl;
    
    Airfoil f;
    f.readCsv("doc/example/NACA2216.csv");
    
    Spline s;
    s.points.push_back(Vector3d(0,0,0));
    s.points.push_back(Vector3d(1,0,0));
    s.points.push_back(Vector3d(1,1,0));
    s.points.push_back(Vector3d(0,1,0));
    s.points.push_back(Vector3d(-1,2,0));
    s.points.push_back(Vector3d(3,0,0));
    s.calculateSpline();
    
    const int n = 101;
    MatrixXd points(n,3);
    VectorXf ts = VectorXf::LinSpaced(n, 0.0, 1.0);
    for(unsigned int i = 0; i<n; i++) {
        double t = ts(i);
        Vector3d pnt = s.getPoint(t);
        points.row(i) = pnt.transpose();
    }
    cout << points << endl;
    writeToCSVfile("points.csv",points);
    
    return 0;
}


/*
#include <plplot/plplot.h>
#include <plplot/plstream.h>

int main()
{
    const int NSIZE = 4;
    double xmin = 0., xmax = 5., ymin = 0., ymax = 5.;
    
	double x[4] = {0,1,1,2};
	double y[4] = {0,0,1,1};

    cout << "A" << endl;
    plstream pls;
    cout << "B" << endl;
    pls.init();
    cout << "C" << endl;
    pls.env( xmin, xmax, ymin, ymax, 0, 0 );
    cout << "D" << endl;
    pls.lab( "x", "y", "XY-Plot" );
    cout << "E" << endl;
    pls.line( NSIZE, x, y );
    cout << "F" << endl;

    return 0;
}
*/

