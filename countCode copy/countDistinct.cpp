#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

int main() {
    set<string> s;
    string ip;
    ifstream inFile;

    inFile.open("data.txt");

    if (!inFile.is_open()) { 
      cout << "Data file not found :-(" << endl;
      exit(1);
    }

    while(inFile >> ip)
        s.insert(ip);

    cout << "Distinct: " << s.size() << endl;
    return 0;
}