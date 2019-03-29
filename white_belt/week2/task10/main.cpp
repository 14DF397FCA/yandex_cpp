#include <iostream>
#include <vector>

using namespace std;

const vector<int> MONTH_LENGTHS = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTH_COUNT = MONTH_LENGTHS.size();

int main() {
    int q = 0;
    cin >> q;
    int month_id = 0;
    vector<vector<string>> days(MONTH_LENGTHS[month_id]);
    for (int i = 0; i < q; ++i) {
        string operation = "";
        cin >> operation;
        if (operation == "ADD") {
            int day_id = 0;
            string task = "";
            cin >> day_id >> task;
            days[day_id - 1].push_back(task);
        } else if (operation == "DUMP") {
            int day_id = 0;
            cin >> day_id;
            --day_id;
            int task_size = days[day_id].size();
            cout << task_size << " ";
            if (task_size > 0) {
                for (auto &t : days[day_id]) {
                    cout << t << " ";
                }
            }
            cout << endl;
        } else if (operation == "NEXT") {
            const int old_month_length = MONTH_LENGTHS[month_id];
            month_id = (month_id + 1) % MONTH_COUNT;
            const int new_month_length = MONTH_LENGTHS[month_id];
            if (new_month_length < old_month_length) {
                vector<string> &last_day_concerns = days[new_month_length - 1];
                for (int day = new_month_length; day < old_month_length; ++day) {
                    last_day_concerns.insert(end(last_day_concerns), begin(days[day]), end(days[day]));
                }
            }
            days.resize(new_month_length);
        } else {
            cout << "Unsupported action" << endl;
        }

    }
    return 0;
}
/*
20
ADD 5 Salary
ADD 5 Duck
DUMP 5
NEXT
DUMP 5
DUMP 5
DUMP 5
ADD 5 Buy


12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
 */
