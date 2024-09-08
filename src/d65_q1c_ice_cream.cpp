#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;
    // TODO: try using map inside of vector of pairs
    vector<pair<int, int>> change(n);  // (day, new amount)
    for (int i = 0; i < n; i++) cin >> change[i].first >> change[i].second;
    change.push_back(make_pair(0, start));
    sort(change.begin(), change.end());

    // pre-calculate
    int last_change_day = (change.end() - 1)->first;
    int current = start;
    auto change_lookup = change.begin();

    int this_sum = 0;
    vector<int> sum(last_change_day + 1);
    for (int i = 0; i <= last_change_day; i++) {
        if (change_lookup->first == i) {
            current = change_lookup->second;
            change_lookup++;
        }
        this_sum += current;
        sum[i] = this_sum;
    }

    // for (auto& e : sum) cout << e << ' ';
    // cout << endl;

    for (int i = 0; i < m; i++) {
        int target, nft_day;
        cin >> target >> nft_day;
        auto idx = lower_bound(sum.begin(), sum.end(), target) - sum.begin();

        if (idx > nft_day) {
            target += sum[nft_day];
            // cout << target << "t-";
            idx = lower_bound(sum.begin(), sum.end(), target) - sum.begin();
        }

        if (idx == last_change_day + 1) {
            // cout << 'b';
            int remaining = target - sum[idx - 1];
            cout << idx + ceil((float)remaining / current) - 1 << ' ';
        } else
            cout << idx << ' ';
    }
}