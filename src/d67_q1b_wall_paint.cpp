#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

#define DEBUG

inline void print_intent(const bool& valid, const int& index, const int& from, const int& to) {
#ifdef DEBUG
    if (valid)
        cout << "\x1b[32mValid paint #" << index << ": " << from << " to " << to << "\x1b[m" << endl;
    else
        cout << "\x1b[31mInvalid paint #" << index << ": " << from << " to " << to << "\x1b[m" << endl;
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

    vector<tuple<int, int, int>> begins, ends;  // pos, paint_idx, current_layer
    get<5>(begins.front());

    for (auto& p : attempts) {
        const int &begin = p.first, end = p.second;
    }
}