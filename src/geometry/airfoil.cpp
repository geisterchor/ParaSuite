/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#include "airfoil.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
using namespace parasuite::geometry;

void Airfoil::readCsv(string filename, unsigned int startline) {
    ifstream f(filename.c_str());
    
    if(!f) {
        throw new runtime_error("Airfoil::readCsv - Cannot open file '"+filename+"'!");
    }
    
    string line, col;
    unsigned int i=0;
    unsigned int n;
    while(getline(f,line)) {
        if(++i > startline) {
            n=0;
            Vector2d p;
            istringstream ss(line);
            while(getline(ss,col,',')) {
                p[n++] = boost::lexical_cast<double>(col);
            }
            if (n != 2) {
                throw new runtime_error("Airfoil CSV has an incorrect format");
            }
            points.push_back(p);
        }
    }
    
    f.close();
}
