#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

vector<string> comma_str_to_vector_str(const string &data) {
    vector<string> result;
    string t;
    stringstream ss(data);
    while (getline(ss, t, ',')) {
        result.push_back(t);
    }
    return result;
}

void Print(const vector<string> &data, int margin = 10) {
    for (const string &item : data) {
        cout << setw(margin) << item;
    }
}

void PrintFile2(const string &filename) {
    fstream input(filename);
    int margin = 10;
    if (input) {
        string t;
        while (getline(input, t)) {
            Print(comma_str_to_vector_str(t));
            cout << endl;
        }
    }
}

void PrintFile(const string &filename) {
    fstream input(filename);
    int margin = 10;
    if (input) {
        int n, m;
        input >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = 0;
                input >> x;
                input.ignore(1);
                cout << setw(margin) << x;
                if (j != m - 1) {
                    cout << " ";
                }
            }
            if (i != n - 1) {
                cout << endl;
            }
        }
    }
}

int main() {
    const string source_file = "input.txt";
    PrintFile(source_file);
//    PrintFile2(source_file);
}

return 0;
}