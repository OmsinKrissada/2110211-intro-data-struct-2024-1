#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void increment(vector<bool> &b) {
    for (int i = b.size() - 1; i >= 0; i--) {
        if (!b[i]) {
            b[i] = true;
            break;
        } else {
            b[i] = false;
        }
    }
}

bool compare_fork(vector<vector<int>> &v, int row, int col) {
    int left = 0, right = 0;
    for (int j = row + 1; j < v.size(); j++) {
        left += v[j][col];
    }
    for (int j = row + 1; j < v.size(); j++) {
        right += v[j][col + j - row];
    }
    if (left == right) {
        if (row >= v.size() - 2) return false;
        return compare_fork(v, row + 2, col + 1);
    }
    if (left < right) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> t(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int input;
            cin >> input;
            t[i - 1].push_back(input);
        }
    }

    int sum = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        sum += t[i][idx];
        cout << i << " Summing " << t[i][idx] << endl;

        if (compare_fork(t, i, idx))
            idx++;
        // else if (left == right) {
        // }
    }
    cout << sum;
}