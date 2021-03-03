//
//  main.cpp
//  catchTest
//
//  Created by Christopher Ayala on 2/2/20.
//  Copyright © 2020 lee. All rights reserved.
//
//*************************************************************************************************************************************
// Christopher L. Ayala-Griffin                                                                                                       *
// 801-12-0585                                                                                                                        *
// ccom3034_0U1                                                                                                                       *
// main.cpp                                                                                                                           *
//                                                                                                                                    *
// Given a string of even length, this program returns true if its first half is the same as its second half. Returns false otherwise.*
//*************************************************************************************************************************************

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "/Users/lee/Documents/ccom3034_0U1/catch_test_framework/catch.hpp"

using namespace std;

bool sameString(const string &st) {
    int j = (st.length()/2);
    for (int i = 0; i < (st.length()/2); i++) {
        if (st[i] != st[j]) return false;
        j++;
    }
    return true;
}

TEST_CASE( "Same String", "[sameString]" ) {
    REQUIRE(sameString("caca") == true);
    REQUIRE(sameString("casa") == false);
    REQUIRE(sameString("abxabx") == true);
    REQUIRE(sameString("dadododa") == false);
    REQUIRE(sameString("20202020") == true);
    REQUIRE(sameString("20199102") == false);
}
