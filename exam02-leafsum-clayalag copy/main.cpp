#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "BSTN.h"


using namespace std;

TEST_CASE( "BSTN is tested", "[BSTN]" ) {
    vector<int> v = {8, 9, 5, 2, 4, 10, 1};
    BSTN B;
    for (auto e: v) B.insert(e);
    REQUIRE (B.InOrder() == "1 2 4 5 8 9 10 ");
    REQUIRE (B.BFS() == "8 5 9 2 10 1 4 ");

    vector<int> v1  = {50, 17, 76, 9, 23, 54, 14, 19, 72, 12, 67};
    BSTN B1;
    for (auto e: v1) B1.insert(e);

    CHECK (B1.leafSum() == 98);
}
