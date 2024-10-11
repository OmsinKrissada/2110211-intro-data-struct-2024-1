#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> orders;  // [stop, start]
    int start, stop;
    cin >> start >> stop;
    cout << "1 ";
    orders.emplace(stop, start);
    for (int i = 2; i <= n; i++) {
        int start, stop;
        cin >> start >> stop;

        if (start > prev(orders.end())->first) {
            cout << i << ' ';
            orders.emplace_hint(orders.end(), stop, start);
            continue;
        }

        if (stop < orders.begin()->second) {
            cout << i << ' ';
            orders.emplace_hint(orders.begin(), stop, start);
            continue;
        }

        auto match = orders.lower_bound(start);
        if (match == orders.end() || match->first < start || match->second > stop) {
            cout << i << ' ';
            orders.emplace_hint(match, stop, start);
        }
    }
}