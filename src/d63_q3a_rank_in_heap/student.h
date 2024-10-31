/*
 * SHAMELESSLY ~~YOINKED~~ MODIFIED FROM Submission ID #393739, which was written by another
 * https://grader.nattee.net/submissions/393739
 */

#include <algorithm>
#define endl string("\n")
using namespace std;

static bool init = false;
static vector<int> ranks;

template <class T, class Comp>
size_t CP::priority_queue<T, Comp>::get_rank(size_t pos) const {
    if (!init) {
        vector<pair<int, int>> s(mSize);
        for (int i = 0; i < mSize; i++) {
            s[i] = {mData[i], i};
        }
        if (mLess(T(0), T(1)))
            sort(s.begin(), s.end(), greater());
        else
            sort(s.begin(), s.end());
        ranks.resize(mSize);
        int j = 0, last = s[0].first;
        for (int i = 0; i < mSize; i++) {
            if (s[j].first != s[i].first) j = i;
            ranks[s[i].second] = j;
        }
        init = true;
    }
    return ranks[pos];
}
