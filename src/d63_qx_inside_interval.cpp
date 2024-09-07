#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> r(n);  // [key, value]
    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        r[i] = {from, to};
    }
    sort(r.begin(), r.end());
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        auto p = lower_bound(r.begin(), r.end(), c + 1, [](pair<int, int> a, int b) { return a.first < b; }) - 1;
        if (p >= r.begin() && p < r.end() && c >= p->first && c <= p->second)
            cout << "1 ";
        else
            cout << "0 ";
    }
}