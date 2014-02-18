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
