#include <iostream>

#include "geometry/paraglider.h"
#include "geometry/airfoil.h"

using namespace std;
using namespace parasuite::geometry;

int main(void) {    
    cout << "Hallo Welt!" << endl;
    Paraglider p;
    
    Airfoil f;
    f.readCsv("doc/example/NACA2216.csv");
    
    return 0;
}
