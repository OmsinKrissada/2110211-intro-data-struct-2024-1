#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> buffer(n);
    // powers
    for (int i = 0; i < n; i++) {
        cin >> buffer[i];
    }

    // types
    vector<int> maxes(m, 1);
    set<int> found_types;
    multiset<int> max_pow;
    int min = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (buffer[i] > maxes[t]) {
            if (found_types.count(t)) {
                max_pow.erase(max_pow.find(maxes[t]));
            } else {
                found_types.insert(t);
            }
            max_pow.insert(buffer[i]);

            if (found_types.size() >= m) {
                min = *max_pow.begin();
            }

            maxes[t] = buffer[i];
        }
        cout << min << ' ';
    }
}