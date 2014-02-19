/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */


#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

#include "geometry/paraglider.h"
#include "geometry/airfoil.h"
#include "geometry/spline.h"

using namespace std;
using namespace parasuite::geometry;

int main(void) {    
    cout << "Hallo Welt!" << endl;
    Paraglider p;
    
    Airfoil f;
    f.readCsv("doc/example/NACA2216.csv");
    
    Spline s;
    s.points.push_back(Vector3d(0,0,0));
    s.points.push_back(Vector3d(1,0,0));
    s.points.push_back(Vector3d(1,1,0));
    s.points.push_back(Vector3d(2,1,0));
    s.points.push_back(Vector3d(2,0,0));
    s.calculateSpline();
    
    return 0;
}
