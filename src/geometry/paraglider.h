#ifndef _PARAGLIDER_H
#define _PARAGLIDER_H

#include <list>

#include "rib.h"
#include "sail.h"

using namespace std;

namespace parasuite {
namespace geometry {

    class Paraglider {
        public:
            list<Rib>  ribs;
            list<Sail> topsail;
            list<Sail> bottomsail;
    };

}
}
#endif
