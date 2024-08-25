#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    short n, k;
    cin >> n >> k;

    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        m[name]++;
    }

    vector<short> nums;
    for (auto &e : m) {
        nums.push_back(e.second);
    }
    sort(nums.begin(), nums.end(), greater<int>());

    cout << (nums.size() >= k ? nums[k - 1] : nums[nums.size() - 1]);
}