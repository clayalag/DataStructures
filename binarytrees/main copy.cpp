#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "BSTN.h"


using namespace std;

TEST_CASE( "BSTN is tested", "[BSTN]" ) {
    vector<int> v = {8, 9, 5, 2, 4, 10, 1};
    vector<int> z = {50, 17, 76, 9, 23, 54, 14, 19, 72, 12, 67};
    BSTN B;
    BSTN A;
    for (auto e: v) B.insert(e);
    for (auto e: z) A.insert(e);
    REQUIRE (B.InOrder() == "1 2 4 5 8 9 10 ");
    REQUIRE (B.BFS() == "8 5 9 2 10 1 4 ");

    CHECK (B.leaves() == 3);
    CHECK (B.maxValueLeaf() == 10);
    CHECK (B.height() == 3);
    CHECK (B.successor(B.search(10)) == NULL);
    CHECK (B.successor(B.searchRec(10)) == NULL);
    CHECK (B.successor(B.searchRec(10)) == NULL);
    CHECK (B.successor(B.searchRec(5)) == B.searchRec(8));

    CHECK (A.successor(A.searchRec(23)) == A.searchRec(50));
    CHECK (A.successor(A.searchRec(14)) == A.searchRec(17));
    CHECK (A.height() == 4);
    CHECK (A.leaves() == 3);
}
