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
