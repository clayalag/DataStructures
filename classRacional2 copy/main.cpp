// Rafael A. Arce Nazario
//
// Cliente con pruebas para la clase Racional
//
// Christopher L. Ayala-Griffin
// 801-12-0585
// ccom3034_0U1
// Pruebas e implementación de la clase Racional.
//


#define CATCH_CONFIG_MAIN
#include <iostream>
#include "/Users/lee/Documents/ccom3034_0U1/catch_test_framework/catch.hpp"
#include "Racional.h"
using namespace std;


TEST_CASE("Rational tests", "[rational]") {
    Racional r01;
    Racional r02(10,8);

    REQUIRE(r01.getP() == 0);
    REQUIRE(r01.getQ() == 1);

    REQUIRE(r02.getP() == 10);
    REQUIRE(r02.getQ() == 8);

//    r02.simplificar();
//    ~r02;
    REQUIRE(r02.getP() == 10);
    REQUIRE(r02.getQ() == 8);

    Racional r03;
//    r03 = r02.suma(r01);
    REQUIRE(r02.suma(r01).getP() == 10);
    REQUIRE(r02.suma(r01).getQ() == 8);

    r03 = r01 + r02;

    Racional r04(1000,10000);
    Racional r05(1,2);

    REQUIRE((r04 > r05) == false);
    REQUIRE((r05 > r04) == true);

    r05.display();

    Racional r06(1,2);
    Racional r07(3,5);
    Racional r08;
    r08 = suma(r06,r07);

    REQUIRE((r06 + 5).getP() == 11);
    REQUIRE((r06 + 5).getQ() == 2);

    REQUIRE((5 + r06).getP() == 11);
    REQUIRE((5 + r06).getQ() == 2);

    Racional t01;
    Racional t02(3, 4);
    Racional t03(8, 5);
    t01 = t02 * t03;
    t01.display();
    
    REQUIRE((t02 * 2).getP() == 6);
    REQUIRE((t02 * 2).getQ() == 4);
    
    REQUIRE((2 * t02).getP() == 6);
    REQUIRE((2 * t02).getQ() == 4);
    
    t01 = 2 * t02;
    t01.display();
    t01 = t02 * 2;
    t01.display();
    
    Racional t04(1,2);
    REQUIRE((t04++).getP() == 1);
    REQUIRE(t04.getP() == 2);
    REQUIRE((t04++).getQ() == 3);
    REQUIRE(t04.getQ() == 4);
    
    Racional t05(3,4);
    Racional t06(1,2);
    REQUIRE((t04 == t05) == true);
    REQUIRE((t05 == t06) == false);
    
}
