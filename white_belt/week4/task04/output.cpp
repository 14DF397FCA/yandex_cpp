#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void ReadAll(const string &source_file, const string &target_file) {
    fstream input(source_file);
    ofstream output (target_file);
    if (input) {
        string t;
        while (getline(input, t))
            output << t << endl;
    }
}

int main() {
    const string source = "input.txt";
    const string target = "output.txt";
    ReadAll(source, target);
    return 0;
}