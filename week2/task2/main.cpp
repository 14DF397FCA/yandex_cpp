#include <iostream>
#include <string>

using namespace std;

string reverse_word(string s) {
    string r = "";
    for (int i = s.size() - 1; i >= 0; --i) {
        r += s[i];
    }
    return r;
}

bool IsPalindrom(string s) {
    return reverse_word(s) == s;
}

int main() {
    string s = "x";
    cin >> s;
    cout << IsPalindrom(s);
    return 0;
}