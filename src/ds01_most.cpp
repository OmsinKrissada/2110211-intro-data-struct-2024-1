#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, unsigned short> m;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        m[name]++;
    }

    string max_name;
    unsigned short max_freq = 0;
    for (auto& e : m) {
        if (e.second >= max_freq) {
            max_name = e.first;
            max_freq = e.second;
        }
    }
    cout << max_name << ' ' << max_freq;
}