#include <bits/stdc++.h>
using namespace std;

bool check(int k, vector<int>& v) {
    for (int i = 0; true; i++) {
        for (int nchild = k * i + 1; nchild <= k * i + k; nchild++) {
            if (nchild >= v.size()) return true;
            if (v[i] < v[nchild]) return false;
        }
    }
}

void testcase() {
    int n, k;
    cin >> n >> k;
    vector<int> maybeheap;
    maybeheap.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        maybeheap.push_back(x);
    }
    cout << (check(k, maybeheap) ? "true\n" : "false\n");
}

int main() {
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        testcase();
    }
}