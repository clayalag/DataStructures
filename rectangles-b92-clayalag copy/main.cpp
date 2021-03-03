// Cliente con pruebas para la clase Rectangle
// Christopher L. Ayala-Griffin

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "/Users/lee/Documents/ccom3034_0U1/catch_test_framework/catch.hpp"
#include "Rectangle.h"
using namespace std;


TEST_CASE("Rectangle tests", "[rectangle]") {
    Rectangle r01;
    Rectangle r02(10,8,12,9);
    Rectangle r03(10,4,6,5);
    Rectangle r04;

    REQUIRE(r01.area() == 0);
    REQUIRE(r02.area() == 2);
    REQUIRE(r03.area() == 4);

    REQUIRE(r01.perimeter() == 0);
    REQUIRE(r02.perimeter() == 6);
    REQUIRE(r03.perimeter() == 10);

    REQUIRE((r01 < r02) == true);
    REQUIRE((r02 < r03) == false);
    
    r04 = r02 + r03;
    r04.display();
    r04.scale(2);
    r04.display();
    
}
