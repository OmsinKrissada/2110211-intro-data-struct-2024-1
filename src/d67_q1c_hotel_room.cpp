#include <bits/stdc++.h>
using namespace std;

// vector<int> rooms;
set<pair<int, int>> room_pairs;  // available rooms, floor id (reverse)
int total_room = 0;
int floors, m;

void reserve(int n) {
    if (n > total_room) {
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> output;

    while (n > 0) {
        auto found = room_pairs.lower_bound({n, 0});
        if (found == room_pairs.end()) {
            auto selected = prev(room_pairs.end());
            while (prev(selected)->first == selected->first) selected--;
            output.emplace_back(floors - selected->second, selected->first);
            n -= selected->first;
            total_room -= selected->first;
            room_pairs.erase(selected);
            continue;
        }

        auto p = *found;
        p.first -= n;
        output.emplace_back(floors - p.second, n);
        total_room -= n;
        n -= n;
        room_pairs.erase(found);
        room_pairs.emplace(std::move(p));
    }

    sort(output.begin(), output.end());
    for (auto &e : output) cout << e.first << " " << e.second << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> floors >> m;

    for (int i = 0; i < floors; i++) {
        int k;
        cin >> k;
        room_pairs.emplace(k, floors - 1 - i);  // store floor id in reverse
        total_room += k;
    }

    for (int i = 0; i < m; i++) {
        int want;
        cin >> want;
        reserve(want);
    }
}
