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
