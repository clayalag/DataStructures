// Rafael A. Arce Nazario
//
// Christopher L. Ayala
// 801-12-0585
// ccom3034_0U1
// Cliente con pruebas para la determinar la letra más repetida en un string.
//
//  main.cpp
//  mostFreqChar-clayalag
//
//  Created by Christopher Ayala on 2/13/20.
//  Copyright © 2020 lee. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "/Users/lee/Documents/ccom3034_0U1/catch_test_framework/catch.hpp"
using namespace std;

const int lcRangeSize = 'z' - 'a' + 1;

// Given a string st of lower case letters, returns the most common character in the string.
// If there is more than one most frequent character, returns the null char `\0'

char mostFreqChar(const string &st) {

    // create an initialize the direct address table
    int A[lcRangeSize] = {0};
    int max = 0;
    char letter = 0;
    // traverse the string, counting the frequency of the letters
    for (auto c: st) {
        A[c - 'a']++;
        if (max < A[c - 'a']) {
        max = A[c - 'a'];
        letter = c;
        }
        else if (max==A[c - 'a']){
            letter = '\0';
        }
    }
    return letter;
}

TEST_CASE("mostFreqChar", "[mostFreqChar]") {
    REQUIRE(mostFreqChar("aaa") == 'a');
    REQUIRE(mostFreqChar("") == '\0');
    REQUIRE(mostFreqChar("bobolon") == 'o');
    REQUIRE(mostFreqChar("apestosas") == 's');
    REQUIRE(mostFreqChar("apestosa") == '\0');
    REQUIRE(mostFreqChar("zorra") == 'r');
    REQUIRE(mostFreqChar("uxyzabcdefghijklmnopqrstu") == 'u');
}
