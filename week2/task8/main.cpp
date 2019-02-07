#include <iostream>
#include <vector>

using namespace std;

int get_avg_temp(vector<int> &v) {
    int sum = 0;
    for (auto a : v) {
        sum += a;
    }
    return sum / v.size();
}

int days_temp_high_avg(int &avg, vector<int> &days) {
    int num = 0;
    for (auto i : days) {
        if (i > avg) {
            ++num;
        }
    }
    return num;
}

vector<int> days_ids_temp_high_avg(int &avg, vector<int> &days) {
    vector<int> ids;
    for (int i = 0; i < days.size(); i++) {
        if (days[i] > avg) {
            ids.push_back(i);
        }
    }
    return ids;
}

void print_result(int &avg_days, vector<int> &ids) {
    cout << avg_days << endl;

    for (auto i : ids) {
        cout << i << " ";
    }
}

int main() {
    int n = 0;
    cin >> n;
    
    vector<int> days(n);
    for (int &day : days) {
        cin >> day;
    }

    int avg_temp = get_avg_temp(days);
    int days_avg_temp = days_temp_high_avg(avg_temp, days);
    vector<int> avg_days = days_ids_temp_high_avg(avg_temp, days);

    print_result(days_avg_temp, avg_days);

    return 0;
}