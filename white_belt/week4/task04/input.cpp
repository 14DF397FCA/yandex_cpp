#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void ReadAll(const string &source_file) {
    fstream input(source_file);
    if (input) {
        string t;
        while (getline(input, t))
            cout << t << endl;
    }
}

int main() {
    const string filename = "input.txt";
    ReadAll(filename);
    return 0;
}