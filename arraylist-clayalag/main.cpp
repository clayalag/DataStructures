#define CATCH_CONFIG_MAIN
#include "/Users/lee/Documents/ccom3034_0U1/catch_test_framework/catch.hpp"
#include "ArrayList.h"



TEST_CASE( "ArrayList", "[ArrayList]" ) {
    ArrayList L;
    REQUIRE(L.getSize() == 0);

    L.append(6);
    L.append(9);
    REQUIRE(L.getSize() == 2);
    REQUIRE(L.at(0) == 6);
    REQUIRE(L.at(1) == 9);
    L.prepend(12);
    REQUIRE(L.getSize() == 3);
    REQUIRE(L.at(0) == 12);
    REQUIRE(L.at(1) == 6);
    REQUIRE(L.at(2) == 9);
    L.insertAt(4, 1);
    REQUIRE(L.getSize() == 4);
    REQUIRE(L.at(0) == 12);
    REQUIRE(L.at(1) == 4);
    REQUIRE(L.at(2) == 6);
    REQUIRE(L.at(3) == 9);
    L.remove(2);
    REQUIRE(L.getSize() == 3);
    REQUIRE(L.at(0) == 12);
    REQUIRE(L.at(1) == 4);
    REQUIRE(L.at(2) == 9);
    
}
