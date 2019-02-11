#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int q = 0;
    cin >> q;
    map<set<string>, int> stops;
    for (int i = 0; i < q; ++i) {
        int n = 0;
        cin >> n;
        set<string> t;
        for (int j = 0; j < n; ++j) {
            string stop = "";
            cin >> stop;
            t.insert(stop);
        }
        if (stops.count(t) == 0) {
            //  add new bus
            const int new_bus = stops.size() + 1;
            stops[t] = new_bus;
            cout << "New bus " << new_bus << endl;
        } else {
            //  bus already exists
            cout <<"Already exists for " << stops[t] << endl;
        }
    }

    return 0;
}