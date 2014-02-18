#ifndef _AIRFOIL_H
#define _AIRFOIL_H

#include <armadillo>
#include <list>

using namespace std;
using namespace arma;

namespace parasuite
{
namespace geometry {

    class Airfoil {
        private:
            list<vec> points;
        public:
            void readCsv(string filename, unsigned int startline = 1);
    };
}
}
#endif
