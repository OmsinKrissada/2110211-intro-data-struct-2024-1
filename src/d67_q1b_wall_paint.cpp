#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int length, m;
    cin >> length >> m;

    vector<pair<int, int>> v(m);
    for (int i = 0; i < m * 2; i++) {
        int x, c, d;
        cin >> x >> c >> d;
        if (d == 0) {
            v[c - 1].first = x - 1;
        } else {
            v[c - 1].second = x - 1;
        }
    }

    // vector<pair<int, int>> approved;
    vector<int> layers(length, 0);
    // vector<pair<int, int>> ends; // end, begin
    // for (auto& p : v) {
    //     auto rbound = upper_bound(ends.begin(), ends.end(), p.second);
    //     if (rbound == ends.end()) continue;
    //     if (rbound->second < p.first) { // approved
    //         ends.push_back
    //     }
    // }

    // for(auto& e: v) cout << e.first << ',' << e.second << ' ';
    // cout << endl;
    vector<int> paint_idx(length, -1);
    for (int idx = 0; idx < m; idx++) {
        auto& p = v[idx];
        int baseline = paint_idx[p.first];
        // if (baseline != paint_idx[p.second]) return false;
        if (p.first == 0 && paint_idx[p.first] != -1) continue;
        if (p.first > 0 && baseline != paint_idx[p.first - 1]) continue;

        if (p.second == m - 1 && paint_idx[p.second] != -1) continue;
        if (p.second < m - 1 && baseline != paint_idx[p.second + 1]) continue;

        for (int i = p.first; i <= p.second; i++) {
            paint_idx[i] = idx;
            layers[i]++;
        }
        // cout << "painted " << p.first << " to " << p.second << endl;
        // for(auto& e: paint_idx) cout << e << ' ';
        // cout << endl;
    }

    cout << *max_element(layers.begin(), layers.end());
}