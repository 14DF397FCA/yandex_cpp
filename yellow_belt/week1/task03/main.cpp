#include <iostream>
#include <tuple>
#include <utility>
#include <map>

using namespace std;

int main() {
//    tuple t(123, "bbb", true);
//    cout << get<1>(t) << endl;
//    pair<int, string> p(2017, "C++");
//    cout << p.first << ": " << p.second;


    map<int, string> digits = {{1, "one"}, {2, "two"}};

    for (const auto &[k, v] : digits) {
        cout << k << ": " << v << endl;
    }
    return 0;
}