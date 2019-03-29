#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int q = 0;
    cin >> q;
    map<string, string> countries;
    for (int i = 0; i < q; ++i) {
        string operation = "";
        cin >> operation;
        if (operation == "DUMP") {
            if (countries.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto &item : countries) {
                    cout << item.first << "/" << item.second << " ";
                }
            }
        } else if (operation == "CHANGE_CAPITAL") {
            string country, capital;
            cin >> country >> capital;
            if (countries.count(country) == 0) {
                countries[country] = capital;
                cout << "Introduce new country " << country << " with capital " << capital << endl;
            } else {
                string old_capital = countries[country];
                if (old_capital == capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    countries[country] = capital;
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to "
                         << capital << endl;
                }
            }
        } else if (operation == "ABOUT") {
            string country;
            cin >> country;
            if (countries.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << countries[country] << endl;
            }
        } else if (operation == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (countries.count(old_country_name) == 0 || countries.count(new_country_name) > 0) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << countries[old_country_name]
                     << " has been renamed to " << new_country_name << endl;
                countries[new_country_name] = countries[old_country_name];
                countries.erase(old_country_name);
            }
        } else {
            string _;
            cin >> _;
            cout << "Unsupported action - " << operation << endl;
        }
    }
    return 0;
}