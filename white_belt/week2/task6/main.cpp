#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Reverse(vector<int> &nums) {
    vector<int> t;
    for (int i = nums.size() - 1; i >= 0; --i) {
        t.push_back(nums[i]);
    }
//    nums.clear();
    nums = t;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);

    for (auto i : numbers) {
        cout << i << " ";
    }
    return 0;
}