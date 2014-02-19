/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#ifndef _AIRFOIL_H
#define _AIRFOIL_H

#include <Eigen/Dense>
#include <list>

using namespace std;
using namespace Eigen;

namespace parasuite
{
namespace geometry {

    class Airfoil {
        private:
            list<Vector2d> points;
        public:
            void readCsv(string filename, unsigned int startline = 1);
    };
}
}
#endif
