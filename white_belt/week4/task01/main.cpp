#include <iostream>

using namespace std;
//
//struct Year {
//    int value;
//    explicit Year (int new_value) {
//        value = new_value;
//    }
//};
//struct Month {
//    int value;
//    explicit Month (int new_value) {
//        value = new_value;
//    }
//};
//struct Day {
//    int value;
//    explicit Day (int new_value) {
//        value = new_value;
//    }
//};
//
//struct Date {
//    int year;
//    int month;
//    int day;
//
//    Date(Year new_year, Month new_month, Day new_day) {
//        year = new_year.value;
//        month = new_month.value;
//        day = new_day.value;
//    }
//};
//
//void PrintDate(const Date &d) {
//    cout << d.year << "-" << d.month << "-" << d.day << endl;
//}
//
//int main() {
//    Date day = {Year{2012}, Month{05}, Day(31)};
//    PrintDate(day);
//    return 0;
//}

struct Specialization {
    string value;

    explicit Specialization(const string &new_value) {
        value = new_value;
    }
};

struct Course {
    string value;

    explicit Course(const string &new_value) {
        value = new_value;
    }
};

struct Week {
    string value;

    explicit Week(const string &new_value) {
        value = new_value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization &new_specialization, const Course &new_course, const Week &new_week) {
        specialization = new_specialization.value;
        course = new_course.value;
        week = new_week.value;
    }
};

int main() {
    return 0;
}