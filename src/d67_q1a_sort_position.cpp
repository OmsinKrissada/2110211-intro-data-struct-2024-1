#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> sorted(v);
    vector<bool> flags(n, false);
    // vector<int> answer(n);
    sort(sorted.begin(), sorted.end());
    // int prev_val = 0, prev_idx;
    unordered_map<int, int> last_idx;
    for (int i = 0; i < n; i++) {
        int current = v[i];
        int pos;
        if (last_idx.count(current)) {
            pos = last_idx[current] + 1;
        } else
            pos = lower_bound(sorted.begin(), sorted.end(), current) - sorted.begin();

        last_idx[current] = pos;

        while (flags[pos]) {
            pos++;
        }
        v[i] = pos;
        flags[pos] = true;
    }

    for (auto& e : v) cout << e + 1 << ' ';
}