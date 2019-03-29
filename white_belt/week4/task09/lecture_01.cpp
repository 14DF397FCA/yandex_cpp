#include <iostream>
#include <exception>
#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void EnsureNextCharAndSkip(stringstream &s) {
    if (s.peek() != '/') {
        stringstream ss;
        ss << "Expected \"/\", but has \"" << char(s.peek()) << "\"";
        throw runtime_error(ss.str());
    }
    s.ignore(1);
}

Date ParseDate(const string &data) {
    Date date;
    stringstream s(data);
    s >> date.year;
    EnsureNextCharAndSkip(s);
    s >> date.month;
    EnsureNextCharAndSkip(s);
    s >> date.day;
    return date;
}

int main() {
//    string date_str = "2012/05/31";
    string date_str = "2012a05b31";
    try {
        Date date = ParseDate(date_str);
        cout << setw(2) << setfill('0') << date.year << "-"
             << setw(2) << setfill('0') << date.month << "-"
             << setw(2) << setfill('0') << date.day << endl;
    } catch (exception &ex) {
        cout << "Exception happens: " << ex.what() << endl;
    }

    return 0;
}