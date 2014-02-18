/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#ifndef _RIB_H
#define _RIB_H

#include <armadillo>
#include "spline.h"

using namespace std;
namespace parasuite
{
namespace geometry {

    class Rib {
        public:
            double cordlength;
            vec rotation;
            Spline topsailSpline;
            Spline bottomsailSpline;
            double cellopening_start, cellopening_end;
    };

}
}

#endif
