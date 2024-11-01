#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_ancestor(const ll& k, ll a, ll b) {
    b = (b - 1) / k;
    if (b == a) return true;
    if (b < a) return false;
    return is_ancestor(k, a, b);
}

ll height(const ll& k, const ll& a) {
    return log2((a + 1) * (k - 1)) / log2(k);
}

int relation(ll S, ll a, ll b) {
    if (height(S, a) == height(S, b)) return 4;
    if ((a - 1) / S == b || (b - 1) / S == a) return 1;
    if (is_ancestor(S, a, b) || is_ancestor(S, b, a)) return 2;
    return 3;
}

/*

    0
 1  2  3
456789

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll S, a, b;
    cin >> n;
    while (n--) {
        cin >> S >> a >> b;
        cout << relation(S, a, b) << " ";
    }
    cout << endl;
}