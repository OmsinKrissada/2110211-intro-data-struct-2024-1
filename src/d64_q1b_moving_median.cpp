#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

inline int median(const vector<int> &v) {
    int size = v.size();
    return size % 2 != 0 ? *(v.begin() + size / 2) : (*(v.begin() + size / 2) + *(v.begin() + size / 2 + 1)) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, w;
    cin >> n >> w;

    vector<int> frame(w + 1);
    queue<int> ordered_frame;
    for (int i = 0; i <= w; i++) {
        int in;
        cin >> in;
        frame[i] = in;
        ordered_frame.push(in);
    }
    sort(frame.begin(), frame.end());
    cout << median(frame) << ' ';

    for (int i = 0; i < n - w - 1; i++) {
        int current;
        cin >> current;
        ordered_frame.push(current);
        frame.erase(lower_bound(frame.begin(), frame.end(), ordered_frame.front()));
        frame.insert(lower_bound(frame.begin(), frame.end(), current), current);
        ordered_frame.pop();
        cout << median(frame) << ' ';
    }
}