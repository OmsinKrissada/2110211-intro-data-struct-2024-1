#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int deck[n];
    bool deck_flag[n] = {false};  // true = used
    for (auto& e : deck) {
        cin >> e;
    }
    sort(deck, deck + n);

    for (int i = 0; i < m; i++) {  // round
        int n_card;
        cin >> n_card;
        for (int j = 0; j < n_card; j++) {
            int card;
            cin >> card;
            int selected_pos = upper_bound(deck, deck + n, card) - deck;
            while (selected_pos < n && deck_flag[selected_pos]) {
                selected_pos++;
            }

            // check game conditions
            if (selected_pos == n) {
                cout << i + 1;
                return 0;
            }

            deck_flag[selected_pos] = true;
        }
    }
    cout << m + 1;
}
