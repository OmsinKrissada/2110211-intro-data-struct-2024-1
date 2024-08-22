/*
 * I believe this task actually wants you to use `lower_bound` & `upper_bound`.
 * I didn't know about them so I wrote a binary search lol
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int nearest_search(vector<int> &v, int target) {
    auto begin = v.begin();
    auto end = v.end();

    while (true) {
        int size = end - begin;
        int mid = size / 2;
        if (size == 1) return *begin;

        if (abs(target - *(begin + mid)) <= abs(target - *(begin + mid - 1))) {
            begin = begin + mid;
        } else {
            end = begin + mid;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        v.push_back(size);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        int size;
        cin >> size;
        cout << nearest_search(v, size) << ' ';
    }
}