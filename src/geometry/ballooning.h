/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#ifndef _BALLOONING_H
#define _BALLOONING_H

#include "spline.h"

namespace parasuite {
namespace geometry {

    class Ballooning {
        public:
            Spline shapeSpline;
            double amplitude;
    };

}
}

#endif
