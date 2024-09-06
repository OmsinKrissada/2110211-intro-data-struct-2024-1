#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// on sorted vector
int median(const vector<int> &v) {
    int size = v.size();
    return size % 2 != 0 ? *(v.begin() + size / 2) : (*(v.begin() + size / 2) + *(v.begin() + size / 2 + 1)) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, w;
    cin >> n >> w;

    // intentionally store as vector<int> before processing, to replicate actual expected execution time in the original task present in Midterm '64
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> frame(v.begin(), v.begin() + w + 1);
    sort(frame.begin(), frame.end());
    cout << median(frame) << ' ';

    for (int i = 1; i < n - w; i++) {
        frame.erase(lower_bound(frame.begin(), frame.end(), v[i - 1]));
        frame.push_back(v[i + w]);
        sort(frame.begin(), frame.end());
        cout << median(frame) << ' ';
    }
}