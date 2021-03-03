#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ArrayList.h"



TEST_CASE( "ArrayList", "[ArrayList]" ) {
    ArrayList L;
    REQUIRE(L.getSize() == 0);

    L.append(6);
    L.append(9);
    REQUIRE(L.getSize() == 2);
    REQUIRE(L.at(0) == 6);
    REQUIRE(L.at(1) == 9);

    L.insertAt(42, 2);
    REQUIRE(L.getSize() == 3);
    REQUIRE(L.at(0) == 6);
    REQUIRE(L.at(2) == 42);

    L.insertAt(88, 0);
    REQUIRE(L.getSize() == 4);
    REQUIRE(L.at(0) == 88);
    REQUIRE(L.at(2) == 9);

    L.prepend(90);
    REQUIRE(L.getSize() == 5);
    REQUIRE(L.at(0) == 90);
    REQUIRE(L.at(1) == 88);
    REQUIRE(L.at(1) == 88);

    ArrayList M;
    M.append(10);
    M.append(20);
    M.append(30);
    M.append(40);
    M.remove(1);
    REQUIRE(M.getSize()==3);
    REQUIRE(M.at(1) == 30);

    ArrayList P;
    P = M;
    P.prepend(5);
    REQUIRE(P.at(0) == 5);
    REQUIRE(M.at(0) == 10);

    P = P;
    REQUIRE(P.at(0) == 5);

    ArrayList L1;
    L1.append(9);
    L1.append(5);
    L1.append(4);
    ArrayList L2;
    L2.append(2);
    L2.append(3);
    ArrayList L3;
    L3 = L1 + L2;
    REQUIRE(L3.at(0)==9);
    REQUIRE(L3.at(2)==4);
    REQUIRE(L3.at(4)==3);

    ArrayList L4;
    L4.append(9);
    L4.append(5);
    L4.append(4);
    L4.append(3);
    L4.append(19);
    L4.append(22);
    L4.append(33);
    L4.append(42);
    L4.append(37);
    L4.removeOdds();
    REQUIRE(L4.at(0)==4);
    REQUIRE(L4.at(1)==22);
    REQUIRE(L4.at(2)==42);

    ArrayList L5;
    L5.append(9);
    L5.append(9);
    L5.append(9);
    L5.append(9);
    L5.append(9);
    L5.append(9);
    L5.append(3);
    L5.append(3);
    L5.append(7);
    L5.append(1);
    REQUIRE(L5.mode()==9);
}