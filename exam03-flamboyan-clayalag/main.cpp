#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"


using namespace std;

// function isFlamboyan:
//   Given a binary tree represented using a 1-based array, returns true
//   if tree is a flamboyan.
bool isFlamboyan(const vector<int> &v) {
    bool foundLeaf;
    int i = 1;
    int iIzq = 2 * i;
    int iDere = 2 * i + 1;

    while (v[i] != -1 && iDere <= v.size()) {
        if(v[iIzq] && v[iDere]) {
            if(foundLeaf == true) {
                return false;
            }
            else if(v[iIzq] > v[iDere]) {
                return false;
            }
            else if(v[iIzq] < v[i] && v[i] < v[iDere]) {
                return false;
            }
            else {
                i++;
                iIzq = 2 * i;
                iDere = 2 * i + 1;
            }
        }
        else if(!v[iIzq] && !v[iDere]) {
            foundLeaf = true;
        }
        else if(!v[iIzq] || !v[iDere]) {
            return false;
        }
    }

    return true;
}

TEST_CASE("flamboyan", "[flamboyan]") {
    CHECK(isFlamboyan({-1,5,6,7}) == true);
    CHECK(isFlamboyan({-1,5,7,6}) == false);
    CHECK(isFlamboyan({-1,30,50,70,10,40,50,60,3,9,90,95,60,75,3,10}) == true);
    CHECK(isFlamboyan({-1,30,20,70,10,40,50,60,3,9,90,95,80,75,3,10}) == false);
    CHECK(isFlamboyan({-1,15,50,70,10,40,60}) == false);

    // TODO: create more tests

}
