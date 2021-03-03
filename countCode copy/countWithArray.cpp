// Rafael Arce Nazario
//
// Problem: Given a file called "data.txt" that contains strings, determine the number of uniques.
//
// This solution uses the array data structure to try and solve the problem.
// It declares a array to keep track of the uniques. Then for each string read from the
// file, it searches for that string in the array of uniques. If not found, adds the 
// the string to the array of uniques.


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;



// Given an array and its length, returns true if the key is found in the array.

bool linearSearch(const string a[], int size, string key) {
    for (int i = 0; i < size; i++) {
        if (a[i] == key) return true;
    }
    return false;
}

int main() {

    // Here we assume that we know already that the number of uniques will not be 
    // greater than 1000. If we did not know that number, we would have to keep
    // write code to resize the array if the number of elements to store was 
    // greater than its size.

    int size = 1000;
    string *a = new string[1000]; 

    string ip;
    ifstream inFile;

    inFile.open("data.txt");

    if (!inFile.is_open()) { 
      cout << "Data file not found :-(" << endl;
      exit(1);
    }

    int ctr = 0;

    // Read each string, determine if it is on the array. If not
    // then append it to the array.

    while(inFile >> ip) {
        if (linearSearch(a, ctr, ip) == false) { 
            a[ctr] = ip;
            ctr++;
        }
    }

    cout << "Distinct: " << ctr << endl;
    return 0;
}
