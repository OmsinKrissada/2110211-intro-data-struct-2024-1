#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_item, n_user, n_action;
    cin >> n_item >> n_user >> n_action;

    map<int, int> amount;          // item: amount
    map<int, map<int, int>> bids;  // item: {user: bid price,...}

    for (int i = 1; i <= n_item; i++) {
        cin >> amount[i];
    }

    for (int i = 0; i < n_action; i++) {
        char action;
        int user, item;
        cin >> action >> user >> item;
        if (action == 'B') {
            int price;
            cin >> price;
            bids[item][user] = price;
        } else if (action == 'W') {
            if (bids[item].count(user)) {
                bids[item].erase(user);
            }
        }
    }

    map<int, vector<int>> won;  // user: [items...]
    // cout << bids.size();
    for (auto& bid : bids) {
        if (bid.second.size() == 0) continue;
        vector<pair<int, int>> positions(bid.second.begin(), bid.second.end());
        sort(positions.begin(), positions.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second || a.second == b.second && a.first > b.first; });
        // cout << b.first << ": Selecting " << amount[b.first] << " from ";
        // for (auto& e : positions) cout << "(" << e.first << ", " << e.second << ") ";
        // cout << endl;
        for (int c = 0; c < amount[bid.first] && c < bid.second.size(); c++) {
            auto& pos = positions[c];
            won[pos.first].push_back(bid.first);
            // cout << "Giving " << bid.first << " to " << pos.first << endl;
        }
        // int max_price = 0, max_user;
        // for (auto& pos : b.second) {
        //     if (pos.second > max_price || pos.second == max_price && pos.first > max_user) {
        //         max_price = pos.second;
        //         max_user = pos.first;
        //     }
        // }
        // won[max_user].push_back(b.first);
    }

    for (int i = 1; i <= n_user; i++) {
        auto& items = won[i];
        if (items.size() == 0) {
            cout << "NONE\n";
            continue;
        }
        for (auto& e : items) cout << e << ' ';
        cout << '\n';
    }
}