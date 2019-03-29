#include <iostream>

using namespace std;

class ReversibleString {
public:
    string data;

    ReversibleString() {

    }

    ReversibleString(string new_data) {
        data = new_data;
    }

    void Reverse() {
        string t;
        for (int i = data.size() - 1; i >= 0; --i) {
            t += data[i];
        }
        data = t;
    }

    string ToString() const {
        if (data.empty()) {
            return "";
        } else {
            return data;
        }

    }
};