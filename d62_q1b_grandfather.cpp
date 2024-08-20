#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long gd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<gd, gd> stof;

    for (int i = 0; i < n; i++) {
        gd f, s;
        cin >> f >> s;
        stof.insert(make_pair(s, f));
    }

    for (int i = 0; i < m; i++) {
        gd p1, p2;
        cin >> p1 >> p2;

        if (p1 == p2) {
            cout << "NO\n";
            continue;
        }

        if (!stof.count(p1) || !stof.count(p2)) {
            cout << "NO\n";
            continue;
        }
        gd first_father = stof.at(p1);
        gd second_father = stof.at(p2);

        if (!stof.count(first_father) || !stof.count(second_father)) {
            cout << "NO\n";
            continue;
        }
        gd first_gd = stof.at(first_father);
        gd second_gd = stof.at(second_father);

        cout << (first_gd == second_gd ? "YES" : "NO") << '\n';
    }
}