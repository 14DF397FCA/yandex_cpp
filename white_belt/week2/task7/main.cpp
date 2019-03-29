#include <iostream>

#include <vector>

using namespace std;

vector<int> Reversed(const vector<int> &v) {
    vector<int> t;
    for (int i = v.size() - 1; i >= 0; i--) {
        t.push_back(v[i]);
    }
    return t;
}

int main() {
    vector<int> t = Reversed({1, 5, 3, 4, 2});
    for (auto i : t) {
        cout << i << " ";
    }
    return 0;
}