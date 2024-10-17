#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> found;
    queue<int> q;
    q.push(m);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        found.push_back(i);
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n) q.push(left);
        if (right < n) q.push(right);
    }

    cout << n - found.size() << '\n';
    int look = 0;
    for (int i = 0; i < n; i++) {
        if (found[look] != i)
            cout << i << ' ';
        else
            look++;
    }
}