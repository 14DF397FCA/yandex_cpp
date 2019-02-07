#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q = 0;
    cin >> q;
    vector<bool> is_worry;

    for (int i = 0; i < q; ++i) {
        string code;
        cin >> code;
        if (code == "WORRY_COUNT") {
            cout << count(begin(is_worry), end(is_worry), true) << endl;
        }
        else {
            if (code == "WORRY" || code == "QUIET") {
                int id = 0;
                cin >> id;
                is_worry[id] = (code == "WORRY");
            } else if (code == "COME") {
                int persons = 0;
                cin >> persons;
                is_worry.resize(is_worry.size() + persons, false);
            }
        }
    }

    return 0;
}