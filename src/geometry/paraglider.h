/*
 * PARASUITE
 * http://parasuite.geisterchor.com  
 *
 * Copyright (c) 2014 Malte Janduda <mail@malte-janduda.de>
 * Licensed under the terms of the GNU General Public License, version 3.
 */

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
