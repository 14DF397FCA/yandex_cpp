#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void ReadAll(const string &path) {
    fstream file(path);
    if (file) {
        string t;
        while (getline(file, t))
            cout << t << endl;
    }
}

int main() {
    const string filename = "input.txt";
    ReadAll(filename);
    return 0;
}