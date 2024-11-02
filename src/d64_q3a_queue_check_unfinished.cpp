// https://grader.nattee.net/submissions/473394 is way cleaner

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int mFront, mSize, mCap, last, correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;

        if (mSize > mCap) {
            if (!correction) {
                cout << "WRONG\n";
                continue;
            }
            cout << "WRONG " << (correction == 2 ? mCap : max(max(mSize, last + 1), mFront + 1)) << '\n';
            continue;
        }

        if (mFront >= mCap) {
            if (!correction) {
                cout << "WRONG\n";
                continue;
            }
            cout << "WRONG " << (correction == 1 ? mCap : mFront + 1) << '\n';
            continue;
        }

        if (last != (mFront + mSize) % mCap) {
            if (!correction) {
                cout << "WRONG\n";
                continue;
            }
            if (correction == 4) {
                cout << "WRONG " << (mFront + mSize) % mCap << '\n';
                continue;
            }
            if (correction == 1) {
                cout << "WRONG " << (last - mSize + mCap) % mCap << '\n';
                continue;
            }
            if (correction == 2) {
                cout << "WRONG " << (last - mFront + mCap) % mCap << '\n';
                continue;
            }
            // if (correction == 3) {
            //     cout << "WRONG " <<  << '\n';
            //     continue;
            // }
        }

        cout << "OK\n";
    }
}