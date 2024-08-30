#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> targets;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        targets.push(t);
    }

    vector<int> sums;
    int current_sum = 0;
    queue<int> orders[2];
    for (int i = 0; i < n; i++) {
        int action;
        cin >> action;

        if (action == 1) {  // order
            int app, price;
            cin >> app >> price;
            orders[app - 1].push(price);
        } else if (action == 2) {  // cook
            int selected_app;
            if (orders[0].size() == 0)
                selected_app = 1;
            else if (orders[1].size() == 0)
                selected_app = 0;
            else {
                selected_app = orders[0].front() > orders[1].front();
            }
            int price = orders[selected_app].front();
            orders[selected_app].pop();
            current_sum += price;
            sums.push_back(current_sum);
        }
    }

    while (!targets.empty()) {
        int target = targets.front();
        targets.pop();

        int min = lower_bound(sums.begin(), sums.end(), target) - sums.begin() + 1;
        cout << (min < sums.size() + 1 ? min : -1) << ' ';
    }
}