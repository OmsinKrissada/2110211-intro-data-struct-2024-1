#include <bits/stdc++.h>
using namespace std;

bool is_ancestor(int a, int b) {
    b = (b - 1) / 2;
    if (b == a) return true;
    if (b < a) return false;
    return is_ancestor(a, b);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "a and b are the same node\n";
            continue;
        }
        if (is_ancestor(a, b)) {
            cout << "a is an ancestor of b\n";
            continue;
        }
        if (is_ancestor(b, a)) {
            cout << "b is an ancestor of a\n";
            continue;
        } else
            cout << "a and b are not related\n";
    }
}