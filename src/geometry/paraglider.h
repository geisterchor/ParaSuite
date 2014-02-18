////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                   PARASUITE                                //
//                       Paraglider Engineering Framework                     //
//                       http://parasuite.geisterchor.com                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// Copyright 2014 Malte Janduda                                               //
//                                                                            //
// This file is part of ParaSuite.                                            //
//                                                                            //
// ParaSuite is free software: you can redistribute it and/or modify it under //
// the terms of the GNU General Public License as published by the Free       //
// Software Foundation, either version 3 of the License, or (at your option)  //
// any later version.                                                         //
//                                                                            //
// ParaSuite is distributed in the hope that it will be useful, but WITHOUT   //
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or      //
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   //
// more details.                                                              //
//                                                                            //
// You should have received a copy of the GNU General Public License along    //
// with ParaSuite. If not, see http://www.gnu.org/licenses/.                  //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


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
