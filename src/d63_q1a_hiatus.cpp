#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pubs(n);
    for (auto& e : pubs) {
        int year, month;
        cin >> year >> month;
        e = {year, month};
    }
    sort(pubs.begin(), pubs.end());

    for (int i = 0; i < m; i++) {
        int year, month;
        cin >> year >> month;
        auto sel = lower_bound(pubs.begin(), pubs.end(), make_pair(year, month + 1)) - 1;
        if (sel < pubs.begin())
            cout << "-1 -1 ";
        else if (sel->first == year && sel->second == month)
            cout << "0 0 ";
        else
            cout << sel->first << ' ' << sel->second << ' ';
    }
}