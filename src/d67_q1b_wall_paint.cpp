#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define DEBUG

inline void print_intent(const bool& valid, const int& index, const int& from, const int& to) {
#ifdef DEBUG
    if (valid)
        cout << "\x1b[32mValid paint #" << index << ": " << from << " to " << to << "\x1b[m" << endl;
    else
        cout << "\x1b[31mInvalid paint #" << index << ": " << from << " to " << to << "\x1b[m" << endl;
#endif
}

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

#ifdef DEBUG
    cout << "Wall Length: " << length << endl;
    cout << "Trying to paint " << m << " times" << endl;
    cout << endl;
#endif

    for (int idx = 0; idx < m; idx++) {
        auto& p = v[idx];
        int baseline = paint_idx[p.first];
        // if (baseline != paint_idx[p.second]) return false;
        // if (layers[p.first] != layers[p.second]) continue;
        if (p.first == 0 && paint_idx[p.first] != -1) {
            print_intent(false, idx + 1, p.first + 1, p.second + 1);
            continue;
        }
        if (p.second == m - 1 && paint_idx[p.second] != -1) {
            print_intent(false, idx + 1, p.first + 1, p.second + 1);
            continue;
        }

        if (p.first > 0 && baseline != paint_idx[p.first - 1]) {
            print_intent(false, idx + 1, p.first + 1, p.second + 1);
            continue;
        }
        if (p.second < m - 1 && baseline != paint_idx[p.second + 1]) {
            print_intent(false, idx + 1, p.first + 1, p.second + 1);
            continue;
        }

        if (baseline != paint_idx[p.second]) {
            print_intent(false, idx + 1, p.first + 1, p.second + 1);
            continue;
        }

        bool isSameLayer = true;
        for (int i = p.first + 1; i <= p.second; i++) {
            if (paint_idx[i] != baseline) {
                isSameLayer = false;
                break;
            }
        }
        if (!isSameLayer) {
            print_intent(false, idx, p.first + 1, p.second + 1);
            continue;
        }

        for (int i = p.first; i <= p.second; i++) {
            paint_idx[i] = idx;
            layers[i]++;
        }

#ifdef DEBUG
        print_intent(true, idx + 1, p.first + 1, p.second + 1);
        cout << "layers:        ";
        for (auto& e : layers) cout << e << ' ';
        cout << endl;
        cout << "top paint idx: ";
        for (auto& e : paint_idx) cout << e << ' ';
        cout << endl;
        cout << "               ";
        for (int i = 0; i < length; i++) cout << (i == p.first || i == p.second ? "^ " : "  ");
        cout << endl;
#endif
    }

    cout << *max_element(layers.begin(), layers.end()) << endl;
}