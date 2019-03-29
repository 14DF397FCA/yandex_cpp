#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "";
    cin >> str;
    int i = 0, f_count = 0;
    for (auto c : str) {
        if (c == 'f') {
            f_count++;
        }

        if (f_count == 2) {
            cout << i;
            break;
        }
        ++i;
    }
    if (f_count == 1) {
        cout << -1;
    } else if (f_count == 0) {
        cout << -2;
    }
    return 0;
}