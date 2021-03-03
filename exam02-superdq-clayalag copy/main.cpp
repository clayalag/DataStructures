#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "superDeque.h"


using namespace std;

TEST_CASE( "superDeque is tested", "[superDeque]" ) {
    superDeque D;
    D.push_front(10);
    CHECK(D.front() == 10);
    D.push_back(20);
    CHECK(D.back() == 20);
    D.push_front(30);
    CHECK(D.front() == 30);

    D.pop_front();
    CHECK(D.front() == 10);
    CHECK(D.back() == 20);

    D.push_back(40);
    D.push_front(50);
    CHECK(D.front() == 50);
    CHECK(D.back() == 40);

    D.insert(1, 60);
    CHECK(D.front() == 50);
    CHECK(D.back() == 40);
    D.remove(3);
    CHECK(D.front() == 50);
    CHECK(D.back() == 40);
    D.pop_front();
    CHECK(D.front() == 60);
    D.pop_back();
    CHECK(D.back() == 10);
}
