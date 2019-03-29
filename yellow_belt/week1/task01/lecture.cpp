#include <iostream>
#include <vector>
#include <limits>
#include <set>

using namespace std;

enum class RequestType {
    ADD,
    REMOVE,
    NEGATE
};

void ProcessRequest(
        set<int> &numbers,
        RequestType request_type,
        int request_data) {
    if (request_type == RequestType::ADD) {
        numbers.insert(request_data);
    } else if (request_type == RequestType::REMOVE) {
        numbers.erase(request_data);
    } else if (request_type == RequestType::NEGATE) {
        if (numbers.count(request_data) == 1) {
            numbers.erase(re);
            numbers.insert(-request_data);
        }
    }
}

int main() {
    int32_t i1 = 1215;
    uint64_t i2 = 115;

//    int x = -1;
//    unsigned y = 1;
//    cout << (x < y) << endl;
//    cout << (-1 < 1) << endl;
//    cout << (-1 < 1u) << endl;
//    AvgTemp();
    int n = 2;
    int m = 3;
    vector<int> v = {1, 4, 5, 67, 5, 356, 7, 11, 36};
//    for (size_t i = 0; i + 1 < v.size(); ++i) {
//        cout << v[i] << endl;
//    }
    for (size_t i = n + 1; i + m <= v.size(); ++i) {
        cout << v[i] << endl;
    }

//    vector<int> xv = {4,5,6};
//    for (int i = 0; i < xv.size(); ++i) {
//        cout << i << " " << xv[i] << endl;
//    }

//    int i = 2000000000;
//    cout << i << endl;
//    i *= 2;
//    cout << i << endl;

//    cout << sizeof(int16_t) << endl;
//    cout << sizeof(int32_t) << endl;
//    cout << sizeof(int64_t) << endl;
//    cout << sizeof(int) << endl;
//    cout << sizeof(long int) << endl;

//    cout << numeric_limits<int>::min() << " : " << numeric_limits<int>::max() << endl;
//    cout << numeric_limits<long int>::min() << " : " <<numeric_limits<long int>:: max() << endl;

//    cout << numeric_limits<int>::max() + 1 << endl;
//    cout << numeric_limits<int>::min() - 1 << endl;

//    cout << numeric_limits<int32_t>::max() << endl;
//    unsigned x = 2000000000;
//    unsigned y = 1000000000;
//
//    cout << (x + y) / 2 << endl;


    return 0;
}