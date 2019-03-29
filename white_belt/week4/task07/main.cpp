#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string firstname;
    string lastname;
    int day;
    int month;
    int year;
};

void PrintStudentName(const Student &student) {
    cout << student.firstname << " " << student.lastname << endl;
}

void PrintStudentDate(const Student &student) {
    cout << student.day << "." << student.month << "." << student.year << endl;
}

vector<Student> MakeStudentsList() {
    vector<Student> students;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string first_name, last_name;
        int year, month, day;
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back({first_name, last_name, day, month, year});
    }
    return students;
}

Student GetStudentByID(const vector<Student> &students, int id) {
    return students[id - 1];
}

void ExecuteRequests(const vector<Student> &students) {
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string operation;
        int id = 0;
        cin >> operation >> id;
        if (operation == "name" && id > 0 && id <= students.size()) {
            PrintStudentName(GetStudentByID(students, id));
        } else if (operation == "date" && id > 0 && id <= students.size()) {
            PrintStudentDate(GetStudentByID(students, id));
        } else {
            cout << "bad request" << endl;
        }
    }
}

int main() {
    vector<Student> students;
    ExecuteRequests(MakeStudentsList());
    return 0;
}