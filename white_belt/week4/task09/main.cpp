#include <iostream>
#include <exception>
#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

bool EnsureEqual(const string &s1, const string &s2) {
    if (s1 == s2) {
        return true;
    } else {
        stringstream ss;
        ss << s1 << " != " << s2;
        throw runtime_error(ss.str());
    }
}

int main() {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error &e) {
        cout << e.what() << endl;
    }
    return 0;
}