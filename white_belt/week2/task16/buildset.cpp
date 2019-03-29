#include <set>
#include <iostream>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string> &m) {
    set<string> result;
    for (const auto &item : m) {
        result.insert(item.second);
    }
    return result;
}