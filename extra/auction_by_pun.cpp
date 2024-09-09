#include <algorithm>
#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl;

class bidComparator {
   public:
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int items, bidders, actions;
    cin >> items >> bidders >> actions;

    int availability[items + 1];
    for (int i = 1; i <= items; i++) {
        cin >> availability[i];
    }

    std::vector<std::pair<int, int>> db[items + 1];

    for (int i = 0; i < actions; i++) {
        char action;
        cin >> action;

        if (action == 'B') {
            int bidder, item, bid;
            cin >> bidder >> item >> bid;
            auto itr = std::find_if(db[item].begin(), db[item].end(), [bidder](const std::pair<int, int>& p) {
                return p.first == bidder;
            });

            if (itr != db[item].end()) {
                itr->second = bid;
            } else {
                db[item].push_back({bidder, bid});
            }

        } else {
            int bidder, item;
            cin >> bidder >> item;
            auto itr = std::find_if(db[item].begin(), db[item].end(), [bidder](const std::pair<int, int>& p) {
                return p.first == bidder;
            });

            if (itr != db[item].end()) {
                db[item].erase(itr);
            }
        }
    }

    std::vector<int> biddersDB[bidders + 1];

    for (int i = 1; i <= items; i++) {
        std::sort(db[i].begin(), db[i].end(), bidComparator());

        int availableItems = availability[i];
        for (int j = 0; j < availableItems && j < db[i].size(); j++) {
            biddersDB[db[i][j].first].push_back(i);
        }
    }

    for (int i = 1; i <= bidders; i++) {
        if (biddersDB[i].empty()) {
            cout << "NONE\n";
        } else {
            for (int item : biddersDB[i]) {
                cout << item << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
