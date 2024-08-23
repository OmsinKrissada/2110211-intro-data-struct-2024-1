#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        m[name]++;
    }

    for (auto &e : m) {
        if (e.second > 1) cout << e.first << ' ' << e.second << endl;
    }
}