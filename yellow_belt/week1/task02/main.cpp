#include <iostream>

using namespace std;

int main() {
    uint32_t n = 0;
    unsigned R;

    cin >> n >> R;

    uint64_t blocks_weight = 0;

    for (int i = 0; i < n; ++i) {
        int32_t W = 0, H = 0, D = 0;
        cin >> W >> H >> D;
        blocks_weight += static_cast<uint64_t>(W) * H * D;
    }

    cout << blocks_weight * R << endl;

    return 0;
}