#include <bits/stdc++.h>
using namespace std;

inline void print_intent(const bool& valid, const int& index, const int& from, const int& to) {
#ifdef DEBUG
    if (valid)
        cout << "\x1b[32mValid paint #" << index + 1 << ": " << from + 1 << " to " << to + 1 << "\x1b[m" << endl;
    else
        cout << "\x1b[31mInvalid paint #" << index + 1 << ": " << from + 1 << " to " << to + 1 << "\x1b[m" << endl;
#endif
}

int main() {
    int length, m;
    cin >> length >> m;

    vector<pair<int, int>> attempts(m);
    for (int i = 0; i < m * 2; i++) {
        int x, c, d;
        cin >> x >> c >> d;
        if (d == 0) {
            attempts[c - 1].first = x - 1;
        } else {
            attempts[c - 1].second = x - 1;
        }
    }

#ifdef DEBUG
    cout << "Wall Length: " << length << endl;
    cout << "Trying to paint " << m << " times: ";
    for (auto& e : attempts) cout << "(" << e.first + 1 << ", " << e.second + 1 << ") ";
    cout << endl;
#endif

    // vector<int> layers(length, 0);

    map<int, pair<bool, int>> painted;  // pos: (isStartingPoint?, currentLayer)
    painted[attempts[0].first] = make_pair(true, 1);
    painted[attempts[0].second] = make_pair(false, 1);
    // fill(layers.begin() + attempts[0].first, layers.begin() + attempts[0].second + 1, layers[attempts[0].first] + 1);
    print_intent(true, 0, attempts[0].first, attempts[0].second);
    int maxLayer = 1;
    for (auto it = next(attempts.begin()); it != attempts.end(); it++) {
        auto p = *it;
        auto from = painted.lower_bound(p.first);
        auto to = painted.lower_bound(p.second);

        if (from != to || from->first == p.first || from->first == p.second) {
            print_intent(false, it - attempts.begin(), p.first, p.second);
            continue;
        }

        int layer;

        if (from == painted.begin()) {
            layer = 1;
        } else {
            auto previous = prev(from);
            bool isPrevStart = previous->second.first;
            int prevLayer = previous->second.second;

            layer = prevLayer;
            if (isPrevStart) layer++;
            if (layer > maxLayer) maxLayer = layer;
        }

        if (p.first == p.second) {
            painted.emplace_hint(from, p.first, make_pair(false, layer));
        } else {
            painted.emplace_hint(from, p.first, make_pair(true, layer));
            painted.emplace_hint(next(from), p.second, make_pair(false, layer));
        }
        print_intent(true, it - attempts.begin(), p.first, p.second);
    }

    cout << maxLayer;
}