#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    int vals[n];
    for (int i = 0; i < n; i++) cin >> vals[i];
    sort(vals, vals + n);

    for (int i = 0; i < m; i++) {
        int check;
        cin >> check;
        int* lower = lower_bound(vals, vals + n, check - k);
        int* upper = upper_bound(vals, vals + n, check + k);
        cout << upper - lower << ' ';
    }
}