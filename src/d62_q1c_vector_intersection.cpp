#include <iostream>
#include <set>
using namespace std;

int main() {
    int c[2];
    cin >> c[0] >> c[1];

    set<int> s[2];

    for (int round = 0; round < 2; round++) {
        for (int i = 0; i < c[round]; i++) {
            int input;
            cin >> input;
            s[round].insert(input);
        }
    }

    auto min_set = s[0].size() <= s[1].size() ? s[0] : s[1];
    auto max_set = s[0].size() > s[1].size() ? s[0] : s[1];
    for (auto it = min_set.begin(); it != min_set.end(); it++) {
        if (max_set.count(*it)) {
            cout << *it << ' ';
        }
    }
}