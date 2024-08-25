#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int vals[n];
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }

    sort(vals, vals + n);

    for (int i = 0; i < n; i++) {
        if (vals[i] != i + 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}