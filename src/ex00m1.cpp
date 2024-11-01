#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> intervals;
    intervals.reserve(n);
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        intervals.push_back(input);
    }

    int counter = 0, i = 0;
    while (true) {
        for (auto& e : intervals) {
            if (e == 0 || i % e == 0) {
                cout << i << '\n';
                counter++;
                if (counter >= m) return 0;
            }
        }
        i++;
    }
}