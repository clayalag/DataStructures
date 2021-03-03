#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Llist.h"



TEST_CASE( "ArrayList", "[ArrayList]" ) {
    Llist L;
    L.append(1);
    L.append(20);
    L.append(3);
    L.append(4);
    L.nastyAppend(5);
    CHECK(L.at(0) == 1);
    CHECK(L.at(1) == 20);
    CHECK(L.at(2) == 5);

    Llist L1;
    L1.append(1);
    L1.append(20);
    L1.append(3);
    L1.append(4);
    L1.nastyAppend(2);
    CHECK(L1.at(0) == 1);
    CHECK(L1.at(1) == 20);
    CHECK(L1.at(2) == 3);
    CHECK(L1.at(3) == 4);
    CHECK(L1.at(4) == 2);

    Llist L2;
    L2.append(1);
    L2.append(20);
    L2.append(3);
    L2.append(4);
    L2.nastyAppend(30);
    CHECK(L2.at(0) == 30);
}