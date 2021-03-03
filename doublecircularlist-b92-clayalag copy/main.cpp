#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DoubleCircularList.h"


TEST_CASE( "DCL", "[dcl]" ) {
    Job J(1,2,3);
    REQUIRE(J.toString() == "[1 2 3]");

    DoubleCircularList R;
    R.add(Job(1,2,3));
    R.add(Job(2,2,3));
    R.add(Job(3,2,3));
    R.next();
    CHECK(R.toString() == "[2 2 3][3 2 3][1 2 3]");
    CHECK(R.removeCurrent()->data.toString()=="[2 2 3]");
    CHECK(R.toString() == "[3 2 3][1 2 3]");
    R.next();
    CHECK(R.toString() == "[1 2 3][3 2 3]");
    CHECK(R.removeCurrent()->data.toString()=="[1 2 3]");
    CHECK(R.removeCurrent()->data.toString()=="[3 2 3]");
    CHECK(R.removeCurrent() == NULL);
    R.next();
    CHECK(R.isEmpty());

}