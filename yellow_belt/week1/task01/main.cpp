#include <iostream>
#include <vector>

using namespace std;

int AvgTemp(const vector<int> &v) {
    int64_t sum = 0;
    for (const auto &i:v) {
        sum += i;
    }
    return sum / static_cast<int>(v.size());
}

vector<int> GetWarmThenAvg(const int &avg, const vector<int> &v) {
    vector<int> result;
    for (unsigned i = 0; i < v.size(); ++i) {
        if (v[i] > avg) {
            result.push_back(i);
        }
    }
    return result;
}

void PrintResult(const vector<int> &v) {
    for (const auto &i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    unsigned n = 0;
    cin >> n;
    vector<int> days(n);
    for (int &day: days) {
        cin >> day;
    }
    int avg = AvgTemp(days);
    vector<int> v = GetWarmThenAvg(avg, days);
    cout << static_cast<int>(v.size()) << endl;
    PrintResult(v);

}