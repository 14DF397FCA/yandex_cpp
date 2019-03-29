#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, int> BuildCharCounters(string &word) {
    map<char, int> result;
    for (const auto &c : word) {
        ++result[c];
    }
    return result;
}

int main() {
    int q = 0;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        if (BuildCharCounters(s1) == BuildCharCounters(s2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}