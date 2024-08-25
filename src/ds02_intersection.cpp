#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> v1(a), v2(b);
    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        v1[i] = temp;
    }
    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        v2[i] = temp;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int last;
    for (int i = 0; i < a; i++) {
        if (i != 0 && last == v1[i]) continue;
        if (find(v2.begin(), v2.end(), v1[i]) != v2.end()) {
            cout << v1[i] << ' ';
        }
        last = v1[i];
    }
}