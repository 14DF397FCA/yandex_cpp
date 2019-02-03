#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void coutt(string s) {
    cout << s << endl;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<string> s = {s1, s2, s3};
    sort(begin(s), end(s));
    coutt(s[0]);

    return 0;
}