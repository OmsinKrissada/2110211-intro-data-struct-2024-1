#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string shift(string s, int shifts[]) {
    // the task direction guarantees that the size of input string always equals to `l`
    string new_s(s);
    for (int i = 0; i < s.size(); i++) {
        char abs_current = s[i] - 'a';
        char new_abs_char = (abs_current + shifts[i]) % 26;
        new_s[i] = new_abs_char + 'a';
    }
    return new_s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    short l;
    cin >> n >> m >> l;

    int k[l];
    for (int i = 0; i < l; i++) cin >> k[i];

    unordered_set<string> existing;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        existing.insert(input);
    }

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        cout << (existing.count(shift(input, k)) ? "Match\n" : "Unknown\n");
    }
}