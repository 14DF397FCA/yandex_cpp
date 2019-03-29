#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person {
public:
    Person(const string &f_name, const string &l_name, int b_year) {
        birth_year = b_year;
        first_names[birth_year] = f_name;
        last_names[birth_year] = l_name;
    }

    void ChangeFirstName(int year, const string &first_name) {
        if (year >= birth_year) {
            first_names[year] = first_name;
        }
    }

    void ChangeLastName(int year, const string &last_name) {
        if (year >= birth_year) {
            last_names[year] = last_name;
        }
    }

    string GetFullName(int year) const {
        if (year < birth_year) {
            return "No person";
        }
        string first_name = "", last_name = "";
        first_name = get_name_in_year(first_names, year);
        last_name = get_name_in_year(last_names, year);

        return make_fullname(first_name, last_name);
    }

    string GetFullNameWithHistory(int year) const {
        if (year < birth_year) {
            return "No person";
        }
        const string first_name = vector_to_string(get_history_of_first_name(year));
        const string last_name = vector_to_string(get_history_of_last_name(year));
        return make_fullname(first_name, last_name);
    }


private:
    int birth_year;
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

    vector<string> get_history_of_first_name(int year) const {
        return get_name_history(first_names, year);
    }

    vector<string> get_history_of_last_name(int year) const {
        return get_name_history(last_names, year);
    }

    static string get_name_in_year(const map<int, string> &names, int &year) {
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
//    Person person("Polina", "Sergeeva", 1960);
//    for (int year : {1959, 1960}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1965, "Appolinaria");
//    person.ChangeLastName(1967, "Ivanova");
//    for (int year : {1965, 1967}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }

    return 0;
}