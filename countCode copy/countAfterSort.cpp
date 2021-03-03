// Problem: Given a file called "data.txt" that contains strings, determine the number of uniques.
//
// This is the solution that sorts the strings, then traverses the array in search of uniques.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {

    // Here we assume that we know already that the number of uniques will not be 
    // greater than 1000. If we did not know that number, we would have to keep
    // write code to resize the array if the number of elements to store was 
    // greater than its size.

    const int size = 10000;
    string *a = new string[size]; 

    string ip;
    ifstream inFile;

    inFile.open("data.txt");

    if (!inFile.is_open()) { 
      cout << "Data file not found :-(" << endl;
      exit(1);
    }

    int ctr = 0;

    // Read each string, into the array.

    while(inFile >> ip) {
        a[ctr] = ip;
        ctr++;
    }

    sort(a, a+ctr);

    // Traverse the array counting each time that an element is different from the next
    int unique = 1;
    string lastSeen = a[0];
    for (int i = 1; i < ctr; i++) {
        if (a[i] != lastSeen) {
            unique++;
            lastSeen = a[i];
        }
    }

    cout << "Distinct: " << unique << endl;
    
    return 0;
}
