#define CATCH_CONFIG_MAIN


#include "catch.hpp"
#include "stackInt.h"
#include <iostream>

using namespace std;



// Test cases for the stackInt class

TEST_CASE( "stackInt", "[stackInt]" ) {
    stackInt S;
    CHECK(S.empty() == true);
    // cree sus propias pruebas que validen el resto de las funciones
    // (excepto el constructor y destructor)
    S.push(2);
    CHECK(S.top() == 2);

    S.push(1);
    S.push(9);
    S.push(10);
    S.push(3);

    CHECK(S.top() == 3);

    S.pop();
    S.pop();

    CHECK(S.top() == 9);
    CHECK(S.empty() == false);

    S.pop();
    S.pop();
    S.pop();

    CHECK(S.empty() == true);
}