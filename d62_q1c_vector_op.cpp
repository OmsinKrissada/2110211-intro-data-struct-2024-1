#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int op_count;
    cin >> op_count;

    for (short i = 0; i < op_count; i++) {
        string op;
        cin >> op;

        if (op == "pb") {
            int val;
            cin >> val;
            v.push_back(val);
        } else if (op == "sa") {
            sort(v.begin(), v.end());
        } else if (op == "sd") {
            sort(v.begin(), v.end(), [](int l, int r) { return r < l; });
        } else if (op == "r") {
            reverse(v.begin(), v.end());
        } else if (op == "d") {
            int pos;
            cin >> pos;
            v.erase(v.begin() + pos);
        }
    }

    for (int& val : v) {
        cout << val << ' ';
    }
}