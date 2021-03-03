#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "modeStack.h"



TEST_CASE( "modeStack", "[modeStack]" ) {
    modeStack s(20);
    CHECK(s.mode() == -1);
    CHECK(s.empty() == TRUE);

    s.push(5);
    CHECK(s.mode() == 5);

    s.push(8);
    CHECK(s.mode() == -1);

    s.push(5);
    CHECK(s.mode() == 5);

    s.pop();
    CHECK(s.mode() == -1);
    CHECK(s.top() == 8);
    CHECK(s.empty() == FALSE);

    s.pop();
    CHECK(s.mode() == 5);

    s.push(6);
    s.push(8);
    s.push(6);
    s.push(5);
    s.push(6);
    CHECK(s.mode() == 6);
    s.pop();
    CHECK(s.mode() == -1);
    s.pop();
    CHECK(s.mode() == 6);

    modeStack s2(20);
    CHECK(s2.mode() == -1);
    CHECK(s2.empty() == TRUE);

    s2.push(5);
    s2.push(4);
    CHECK(s2.mode() == -1);
    CHECK(s2.top() == 4);
    CHECK(s2.empty() == FALSE);

    s2.push(2);
    CHECK(s2.mode() == -1);

    s2.push(1);
    CHECK(s2.mode() == -1);
    s2.push(2);
    CHECK(s2.mode() == 2);
    CHECK(s2.top() == 2);
    s2.pop();
    CHECK(s2.mode() == -1);
    s2.pop();
    CHECK(s2.mode() == -1);
    s2.pop();
    CHECK(s2.mode() == -1);

}