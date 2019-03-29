#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Print(vector<string> &v) {
    for (const auto &i : v) {
        cout << i << " ";
    }
    cout << endl;
}

string to_lower(string &a) {
    string t = "";
    for (int i = 0; i < a.size() ; ++i) {
        t += tolower(a[i]);
    }
    return t;
}

int main() {
    int n = 0;
    cin >> n;
    vector<string> v(n);
    for (auto &i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end(), [](string a, string b) {
        return to_lower(a) < to_lower(b);
    });

    Print(v);
    return 0;
}