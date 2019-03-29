#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void Print(const vector<string> &names, const vector<double> &values, int margin) {
    for (const auto &i : names) {
        cout << setw(margin) << i << " ";
    }
    cout << endl;
    for (const auto &i : values) {
        cout << setw(margin) << i << " ";
    }
}

void test_f() {
    vector<string> names = {"a", "b", "c"};
    vector<double> values = {5, 0.01, 0.000005};
    cout << fixed << setprecision(10) << setfill('_') << left;
    Print(names, values, 20);
}
int main() {
    test_f();
}