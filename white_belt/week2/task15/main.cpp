#include <iostream>
#include <set>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    set<string> words;
    for (int i = 0; i <n; ++i) {
        string t = "";
        cin >> t;
        words.insert(t);
    }
    cout << words.size();

    return 0;
}