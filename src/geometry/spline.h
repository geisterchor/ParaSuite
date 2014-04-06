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
#include <vector>

using namespace std;
using namespace Eigen;

namespace parasuite
{
namespace geometry {

    class Spline {
        public:
			Spline();

            deque<Vector3d> points;
            unsigned int length_sampling_points;

    		double length();
            void calculateSpline();
            Vector3d getPoint(double tau);
            Vector3d getTauPoint(double tau);
            std::vector<Vector3d> getEquallySpacedPoints(const unsigned int numberOfPoints);
        protected:
            double _length;
            void calculateLength();
            unsigned int n;
            MatrixXd a, b, c, d; 
    };

}
}
#endif
