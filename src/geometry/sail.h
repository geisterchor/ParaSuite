/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#ifndef _SAIL_H
#define _SAIL_H

#include "spline.h"
#include "ballooning.h"

namespace parasuite
{
namespace geometry {

    class Sail {
        public:
            Spline leftSpline;
            Spline rightSpline;
            Ballooning ballooning;
    };

}
}

#endif
