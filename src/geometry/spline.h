/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

#ifndef _SPLINE_H
#define _SPLINE_H

#include <Eigen/Dense>
#include <deque>

using namespace std;
using namespace Eigen;

namespace parasuite
{
namespace geometry {

    class Spline {
        public:
            deque<Vector3d> points;
            
            void calculateSpline();
            Vector3d getPoint(double tau);
        protected:
            unsigned int n;
            MatrixXd a, b, c, d; 
    };

}
}
#endif
