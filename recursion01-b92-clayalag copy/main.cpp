#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include <string.h>

using namespace std;

// Write the missing base case for function largest.
// Function largest should find the largest number in a vector numbers.
// When largest is first called, index will equal A.size()-1.


int largest(const vector<int> &A, int index) {
    if ( index == 0 ) return A[0];
    return max(A[index], largest(A, index-1));
}




// For function multiply, write the missing base case condition and action.
// This function will multiply two numbers x and y.
// You can assume that both x and y are positive.


int multiply(unsigned int x, unsigned int y) {
    if ( x == 1 ) {
        return y;
    } else {
        return multiply(x - 1, y) + y;
    }
}


// For function log, write the missing base case condition
// and the recursive call. This function computes the log of
// n to the base b.
// Examples:
//   * log(2,8) = 3 since 8 = 2*2*2. We can find this by dividing 8 by 2
//     until we reach 1, and we count the number of divisions we make.
// You should assume that n is exactly b to some integer power.


unsigned int log(unsigned int b, unsigned int n ) {
    if (n == 1) {
        return 0;
    } else {
        return log(b,n/b) + 1;
    }
}


// For function addOdd(n) write the missing recursive call.
// This function should return the sum of all postive odd numbers
// less than or equal to n.
// Examples:
// * addOdd(1) -> 1
// * addOdd(2) -> 1
// * addOdd(3) -> 4
// * addOdd(7) -> 16


int addOdd(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n % 2 != 0) { // Odd value
        return addOdd(n-1) + n;
    } else { // Even value
        return addOdd(n - 1);
    }
}


// For function sumOfDigits, write the missing recursive call.
// This function takes a non-negative integer and returns the
// sum of its digits.
// Examples:
// * sumOfDigits(1234) -> 10


int sumOfDigits(int number) {
    if (number < 10)
        return number;
    return sumOfDigits(number / 10) + number % 10;
}


// For function countChr() write the missing part of the recursive call.
// This function should return the number of times that the letter "A"
// appears in string "str".
// Recall that str.substring(a) will return the substring of str from
// position a to the end of str, while str.substring(a, b) will return the
// substring of str starting at position a and continuing to
// (but not including) the character at position b.


int countChr(string str) {
    if (str.length() == 0) {
        return 0;
    }
    int count = 0;
    if (str.substr(0, 1) == "A"){  // equals() no aparece como member function valido de string
        count = 1;
    }
    return count + countChr(str.substr(1));
}

bool kdf(const string &st, int low, int high) {
    if (low >= high) return true;
    return (st[low] == st[high]) && kdf(st, low + 1, high - 1);
}

void foo(int n) {
    if(n==0) return;
    cout << n << endl;
    foo(n-1);
}

void perm(const string &h, const string &t) {
    if (t.length() <= 1) {
        cout << h + t << endl;
        return;
    }
    for (int i = 0; i < t.length(); i++) {
        string hh = t.substr(i,1);
        string tt = t.substr(0, i) + t.substr(i+1);
        perm(h + hh, tt);
    }
}

TEST_CASE( "largest", "[rec]" ) {

    CHECK(largest({1,2,30},2) == 30);
    CHECK(largest({42},0) == 42);
    CHECK(largest({42, 8, 7, 2, 1}, 4) == 42);
    CHECK(largest({42, 8, 77, 2, 1}, 4) == 77);
    CHECK(largest({-42, -1, -77, -34, -11}, 4) == -1);

}

TEST_CASE( "multiply", "[rec]" ) {
    CHECK(multiply(3,2) == 6);
    CHECK(multiply(11,11) == 121);
    CHECK(multiply(42,1) == 42);
    CHECK(multiply(1,7) == 7);
}

TEST_CASE( "log", "[rec]" ) {
    CHECK(log(2,64) == 6);
    CHECK(log(10,100000) == 5);
    CHECK(log(4,64) == 3);
    CHECK(log(2,1024) == 10);
}

TEST_CASE( "addOdd", "[rec]" ) {
    CHECK(addOdd(1) == 1);
    CHECK(addOdd(2) == 1);
    CHECK(addOdd(5) == 9);
    CHECK(addOdd(10) == 25);

}

TEST_CASE( "sumOfDigits", "[rec]" ) {
    CHECK(sumOfDigits(1) == 1);
    CHECK(sumOfDigits(2) == 2);
    CHECK(sumOfDigits(254) == 11);
    CHECK(sumOfDigits(9254) == 20);
    CHECK(sumOfDigits(12345) == 15);
}

TEST_CASE( "countChar", "[rec]" ) {
    CHECK(countChr("AAAxAAA") == 6);
    CHECK(countChr("") == 0);
    CHECK(countChr("BASEDONA") == 2);
    CHECK(countChr("Abecedario") == 1);
    CHECK(countChr("PERRO") == 0);

}

TEST_CASE("kdf", "[kdf]") {
   // CHECK(kdf("caba")== true);
    //CHECK(kdf("caballo")== false);
    foo(4);
    perm("","abcd");
}