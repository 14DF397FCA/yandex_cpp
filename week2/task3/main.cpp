#include <iostream>
#include <vector>

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


vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result = {};
    for (auto word : words) {
        if (IsPalindrom(word) and word.size() >= minLength) {
            result.push_back(word);
        }
    }
    return result;
}

int main() {
    vector<string> v;
    int len = 0;
    cin >> len;


    vector<string> resp = {};

    resp = PalindromFilter(v, len);
    for (auto r : resp) {
        cout << r << " ";
    }
    return 0;
}