/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#ifndef _SPLINE_H
#define _SPLINE_H

#include <armadillo>
#include <list>

using namespace std;
using namespace arma;

namespace parasuite
{
namespace geometry {

    class Spline {
        public:
            list<vec> points;
    };

}
}
#endif
