/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#ifndef _RIB_H
#define _RIB_H

#include <Eigen/Dense>

#include "spline.h"

using namespace std;
using namespace Eigen;

namespace parasuite
{
namespace geometry {

    class Rib {
        public:
            double cordlength;
            Vector3d rotation;
            Spline topsailSpline;
            Spline bottomsailSpline;
            double cellopening_start, cellopening_end;
    };

}
}

#endif
