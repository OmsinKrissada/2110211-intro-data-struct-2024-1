#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void list_erase(vector<int> &v, vector<int> &pos) {
    vector<int> new_v;
    // new_v.reserve(v.size() - pos.size());
    set<int> s(pos.begin(), pos.end());
    for (size_t i = 0; i < v.size(); i++) {
        if (s.count(i)) {
            s.erase(i);
            continue;
        }
        new_v.push_back(v[i]);
    }
    new_v.swap(v);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n), pos(m);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++) cin >> pos[i];
    list_erase(v, pos);
    cout << "After call list_erase" << endl
         << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}