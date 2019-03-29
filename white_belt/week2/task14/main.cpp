#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    int q = 0;
    cin >> q;
    map<vector<string>, int> buses;
    for (int i = 0; i < q; ++i) {
        int n = 0;
        cin >> n;
        vector<string> stops(n);
        for (string &stop : stops) {
            cin >> stop;
        }
        if (buses.count(stops) == 0) {
            const int new_bus = buses.size() + 1;
            buses[stops] = new_bus;
            cout << "New bus " << new_bus << endl;
        } else {
            cout << "Already exists for " << buses[stops] << endl;
        }
    }
    return 0;
}