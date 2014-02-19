ParaSuite
=========
[![Build Status](https://travis-ci.org/geisterchor/ParaSuite.png?branch=master)](https://travis-ci.org/geisterchor/ParaSuite)


Documentation
-------------
* [Project Website](http://parasuite.geisterchor.com)
* [Doxygen API Documentation](http://parasuite.geisterchor.com/doxygen)
* [GitHub Wiki](https://github.com/geisterchor/ParaSuite/wiki)
* [GitHub Issue Tracker](https://github.com/geisterchor/ParaSuite/issues)


Dependencies
------------
### Compiler
ParaSuite is tested with the g++ and clang compiler. But probably it will compile with Intel C++ and Microsoft C++, too.
### Libraries
* [Eigen](http://eigen.tuxfamily.org/) ([MPL 2.0](http://www.mozilla.org/MPL/2.0/))
* [Boost](http://www.boost.org/) ([Boost License](http://www.boost.org/LICENSE_1_0.txt))
* [CxxTest](http://cxxtest.com/) ([LGPL](http://www.gnu.org/licenses/lgpl.html))


Installation
------------
### Ubuntu 12.10 or newer

    sudo apt-get install build-essential g++
    sudo apt-get install libboost-all-dev libeigen3-dev cxxtest
    sudo ln -s /usr/include/eigen3/Eigen /usr/include/Eigen
    sudo apt-get install git
    
    git clone https://github.com/geisterchor/ParaSuite.git
    cd ParaSuite
    make

License
-------
ParaSuite is licensed under [GPL 3.0](http://www.gnu.org/licenses/gpl-3.0).
