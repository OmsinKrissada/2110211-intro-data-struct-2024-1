/*
 *  I'm not gonna delete the comments in this one so you can see what didn't work xd
 *  What I tried and didn't work:
 *  Let each "sum" to be check be "x"
 *  - calculate all possible sums and store in an `unordered_set`, then check if x exist in the set (took 10s for M=N=10000)
 *  - use `set` to store "vals" and loop through them using a pair of iterators, incrementing each iterator to calculate sum of all combinations up to x, breaking if found
 *  - similar to previous attempt but use a sorted vector instead of set for "vals" (ofc also using index instead of incrementing iterators)
 *
 *  So what works?
 *  read it yourself, too lazy to explain lol
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

// #define DEBUG

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    short n, m;
    cin >> n >> m;

    vector<int> vals;
    set<int> vals_set;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (!vals_set.count(val)) {
            vals_set.insert(val);
            vals.push_back(val);
        }
    }

    // cout << "Inserted" << endl;

    sort(vals.begin(), vals.end());
    // cout << "Sorted" << endl;

    // set<int>::iterator before_end = --vals.end();
    // unordered_set<int> sums;

    // cout << "Processed" << endl;

    for (int r = 0; r < m; r++) {
        int check;
        cin >> check;

        // auto ans = (sums.count(check) == 1 ? "YES" : "NO");
        // cout << ans << endl;

        // bool found = false, shouldEnd = false;
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i; j < n; j++) {
        //         if (i > check && j > check) {
        //             shouldEnd = true;
        //             break;
        //         }
        //         if (vals[i] + vals[j] == check) {
        //             found = true;
        //             shouldEnd = true;
        //             break;
        //         }
        //         // sums.insert(*it1 + *it2);
        //         // cout << "inserting\n";
        //     }
        //     if (shouldEnd) break;
        // }

        bool found = false;
        int diff, a;
        for (int i = 0; i < vals.size(); i++) {
            diff = check - vals[i];
            a = vals[i];
            if (diff != vals[i] && vals_set.count(diff)) {
                found = true;
                break;
            }
        }

#ifdef DEBUG
        cout << (found ? "YES" : "NO") << ' ' << check << ' ' << diff << '+' << a << ' ' << '\n';
#else
        cout << (found ? "YES" : "NO") << '\n';
#endif
    }

    // cout << "Finished" << endl;
}