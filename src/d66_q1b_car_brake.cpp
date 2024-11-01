#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> brakes;
    brakes[0] = 0;
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        brakes[t] = d;
    }

    vector<pair<int, int>> agg;
    agg.reserve(n);
    int cs = k;
    for (auto& p : brakes) {
        cs = cs - p.second;
        agg.emplace_back(p.first, cs > 0 ? cs : 0);
    }

#ifdef DEBUG
    for (auto& e : agg) cout << e.first << ":\t" << e.second << "\n";
    cout << endl;
#endif

    for (int i = 0; i < m; i++) {
        int a, q;
        cin >> a >> q;
        if (a == 1) {
            cout << prev(upper_bound(agg.begin(), agg.end(), q, [](int a, pair<int, int> b) { return a < b.first; }))->second << '\n';
        } else {
            auto pos = lower_bound(agg.rbegin(), agg.rend(), q, [](pair<int, int> a, int b) { return a.second < b; });
            if (pos == agg.rbegin() - 1) {
                cout << pos->second + 1 << '\n';
            } else {
                cout << (prev(pos))->first << '\n';
            }

            // cout << lower_bound(agg.begin(), agg.end(), q) - agg.begin() - 1 << '\n';
            // 10
            // 1 1 2 3 3
            // 9 8 6 3 0
        }
    }
}