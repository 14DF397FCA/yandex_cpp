#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    const string source_file = "input.txt";
    fstream input(source_file);
    if (input) {
        string t;
        cout << fixed << setprecision(3);
        while (getline(input, t)) {
            double b = stod(t);
            cout << b << endl;
        }
    }
    return 0;
}