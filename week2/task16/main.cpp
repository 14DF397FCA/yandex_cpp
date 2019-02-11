#include <iostream>
#include <map>
#include <set>
#include "buildset.cpp"

using namespace std;

void print_set(const set<string> &s) {
    for (const auto &item : s) {
        cout << item << endl;
    }
}

int main() {
    print_set(BuildMapValuesSet({{1, "odd"},
                                 {2, "even"},
                                 {3, "odd"},
                                 {4, "even"},
                                 {5, "odd"}
                                }));

    return 0;
}