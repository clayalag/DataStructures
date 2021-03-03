#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int main() {

    queue<string> q;
    string st;
    ifstream inFile("../text01.txt");

    if (!inFile.is_open()) {
        cout << "No pude abrir el file\n";
        exit(1);
    }

    while (inFile >> st) {
        cout << st << endl;
    }

    return 0;
}
