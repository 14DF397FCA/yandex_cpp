#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

/*
 *  vector<int> int_v = {1, 3, 2, 5, 4, 2};

    cout << count_if(begin(int_v), end(int_v), gt2) << endl;
    cout << count_if(begin(int_v), end(int_v), lt2) << endl;
    int thr = 0;
    cin >> thr;
    cout << count_if(begin(int_v), end(int_v), [thr](int x) { return x > thr; }) << endl;
    cout << count_if(begin(int_v), end(int_v), [thr](int x) { return x < thr; }) << endl;

    //  не чётные числа
    int cnt = count_if(begin(v), end(v), [](int x) { return x % 2 != 0;});
 */

void Print(const vector<int> &v) {
    for (const auto &i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });

    Print(v);

    return 0;
}