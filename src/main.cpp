/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#include <iostream>

#include "geometry/paraglider.h"
#include "geometry/airfoil.h"

using namespace std;
using namespace parasuite::geometry;

int main(void) {    
    cout << "Hallo Welt!" << endl;
    Paraglider p;
    
    Airfoil f;
    f.readCsv("doc/example/NACA2216.csv");
    
    return 0;
}
