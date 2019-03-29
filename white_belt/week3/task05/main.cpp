#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        string first_name = "", last_name = "";
        first_name = get_name_in_year(first_names, year);
        last_name = get_name_in_year(last_names, year);

        return make_fullname(first_name, last_name);
    }

    string GetFullNameWithHistory(int year) {
        const string first_name = vector_to_string(get_history_of_first_name(year));
        const string last_name = vector_to_string(get_history_of_last_name(year));
        return make_fullname(first_name, last_name);
    }


private:
    map<int, string> first_names;
    map<int, string> last_names;

    static vector<string> get_name_history(const map<int, string> &names_in_year, int year) {
        vector<string> names;
        for (const auto &item : names_in_year) {
            if (item.first <= year && (names.empty() || names.back() != item.second)) {
                names.push_back(item.second);
            }
        }
        return names;
    }

    vector<string> get_history_of_first_name(int year) {
        return get_name_history(first_names, year);
    }

    vector<string> get_history_of_last_name(int year) {
        return get_name_history(last_names, year);
    }

    static string get_name_in_year(map<int, string> &names, int &year) {
        string name = "";
        for (const auto &item : names) {
            if (item.first <= year) {
                name = item.second;
            }
        }
        return name;
    }

    static string make_fullname(const string &first_name, const string &last_name) {
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + " " + last_name;
        }
    }

    static string vector_to_string(vector<string> names) {
        if (names.empty()) {
            return "";
        }
        reverse(begin(names), end(names));
        string name_with_history = names[0];
        for (int i = 1; i < names.size(); ++i) {
            if (i == 1) {
                name_with_history += " (";
            } else {
                name_with_history += ", ";
            }
            name_with_history += names[i];
        }
        if (names.size() > 1) {
            name_with_history += ")";
        }
        return name_with_history;
    }
};

int main() {
//    Person person;
//
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1990, "Polina");
//    person.ChangeLastName(1990, "Volkova-Sergeeva");
//    cout << person.GetFullNameWithHistory(1990) << endl;
//
//    person.ChangeFirstName(1966, "Pauline");
//    cout << person.GetFullNameWithHistory(1966) << endl;
//
//    person.ChangeLastName(1960, "Sergeeva");
//    for (int year : {1960, 1967}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeLastName(1961, "Ivanova");
//    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}