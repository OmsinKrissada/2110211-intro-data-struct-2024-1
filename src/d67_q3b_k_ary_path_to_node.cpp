#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<size_t> s;

    size_t n, k, want;
    cin >> n >> k >> want;
    
    while (want != 0) {
        s.push((want - 1) % k);
        want = (want - 1) / k;
    }

    cout << s.size() << "\n";
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}