/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#ifndef _AIRFOIL_H
#define _AIRFOIL_H

#include <armadillo>
#include <list>

using namespace std;
using namespace arma;

namespace parasuite
{
namespace geometry {

    class Airfoil {
        private:
            list<vec> points;
        public:
            void readCsv(string filename, unsigned int startline = 1);
    };
}
}
#endif
