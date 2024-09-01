#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    map<int, int> deck;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        deck.insert(make_pair(input, i));
    }
    // sort(deck.begin(), deck.end());
    // deck.sort();

    for (int i = 0; i < m; i++) {  // round
        int n_card;
        cin >> n_card;
        for (int j = 0; j < n_card; j++) {
            int card;
            cin >> card;
            map<int, int>::iterator selected_pos = upper_bound(deck.begin(), deck.end(), card);

            // check game conditions
            if (deck.size() == 0 || selected_pos == deck.end()) {
                cout << i + 1;
                return 0;
            }

            deck.erase(selected_pos);
        }
    }
    cout << m + 1;
}