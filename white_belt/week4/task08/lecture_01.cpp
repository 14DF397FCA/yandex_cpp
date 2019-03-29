#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Duration {
    Duration(int h = 0, int m = 0) {
        int total = h * 60 + m;
        hour = total / 60;
        minute = total % 60;
    }

    int hour;
    int minute;
};

ostream &operator<<(ostream &stream, const Duration &duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ":"
           << setw(2) << duration.minute;
    return stream;
}

istream &operator>>(istream &stream, Duration &duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.minute;
    return stream;
}

Duration operator+(const Duration &d1, const Duration &d2) {
    return {d1.hour + d2.hour, d1.minute + d2.minute};
}

Duration operator-(const Duration &d1, const Duration &d2) {
    return {d1.hour - d2.hour, d1.minute - d2.minute};
}

bool operator<(const Duration &d1, const Duration &d2) {
    if (d1.hour == d2.hour) {
        return d1.minute < d2.minute;
    }
    return d1.hour < d2.hour;
}

void Print(const vector<Duration> &v) {
    for (const Duration &i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    stringstream dur_ss("07:40");
    Duration d1, d2 = {0, 55};
    dur_ss >> d1;
//    cout << d1 + d2 << endl;
    Duration d3 = d1 + d2;
    Duration d4 = d3 - Duration{12, 0};
    vector<Duration> v = {d3, d2, d1, d4};
    Print(v);
    sort(v.begin(), v.end());
    Print(v);
    cout << d4;
    return 0;
}