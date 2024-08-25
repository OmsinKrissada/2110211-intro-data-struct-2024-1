#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, pair<int, int>> subjects, instructors;  // (total score, count)
    for (int i = 0; i < n; i++) {
        string sub, ins;
        short score;
        cin >> sub >> ins >> score;
        subjects[sub].first += score;
        subjects[sub].second += 1;
        instructors[ins].first += score;
        instructors[ins].second += 1;
    }

    cout << fixed << setprecision(2);
    for (auto& e : subjects) cout << e.first << ' ' << (float)e.second.first / e.second.second << endl;
    for (auto& e : instructors) cout << e.first << ' ' << (float)e.second.first / e.second.second << endl;
}