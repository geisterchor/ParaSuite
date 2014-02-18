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
