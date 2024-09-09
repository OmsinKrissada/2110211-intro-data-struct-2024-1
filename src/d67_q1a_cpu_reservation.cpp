#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> orders;  // [start, stop]
    int start, stop;
    cin >> start >> stop;
    cout << "1 ";
    orders.push_back(make_pair(start, stop));
    for (int i = 2; i <= n; i++) {
        int start, stop;
        cin >> start >> stop;
        auto match = lower_bound(orders.begin(), orders.end(), start, [](pair<int, int> l, int r) { return l.second < r; });
        // auto high = low->second;

        if (match == orders.end() || match->second < start || match->first > stop) {
            cout << i << ' ';
            orders.push_back(make_pair(start, stop));
            if (match != orders.end()) sort(orders.begin(), orders.end());
        }
    }
}