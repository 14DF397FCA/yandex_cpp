#include <iostream>
#include <fstream>

using namespace std;

void ReadAll(const string &path) {
    fstream file(path);
    if (file) {
        string t;
        while (getline(file, t))
            cout << t << endl;
    }
}

int main() {
    const string file_name = "./../bla.txt";
    ofstream output(file_name, ios::app);
    output << "Some string" << endl;
//    fstream input(file_name);

    ReadAll(file_name);
//    ifstream input("./../date.txt");
//    int year = 0, month = 0, day = 0;
//    if (input) {
//        input >> year;
//        input.ignore(1);
//        input >> month;
//        input.ignore(1);
//        input >> day;
//        input.ignore(1);
//
//    } else {
//        cout << "File not found!" << endl;
//    }
//    cout << year << "." << month << "." << day << endl;

//    ifstream input("main.cpp");
//    string line;
//    if (input) {
//        while (getline(input, line)) {
//            cout << line << endl;
//        }
//        cout << "Done!" << endl;
//    } else {
//        cout << "File not found!" << endl;
//    }
    return 0;
}