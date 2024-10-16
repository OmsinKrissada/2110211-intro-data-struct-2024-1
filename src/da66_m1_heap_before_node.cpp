#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int depth = log2(n) + 1;

    vector<bool> found(n, false);
    int foundCount = 0;
    queue<int> frame;
    frame.push(m);
    while (!frame.empty()) {
        int i = frame.front();
        frame.pop();
        found[i] = true;
        foundCount++;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n) frame.push(left);
        if (right < n) frame.push(right);
    }

    cout << n - foundCount << '\n';
    for (int i = 0; i < n; i++) {
        if (!found[i]) cout << i << ' ';
    }
}