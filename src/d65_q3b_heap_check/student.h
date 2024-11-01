#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
    // Your code here
    // Return something
    for (size_t i = 0; true; i++) {
        size_t lc = 2 * i + 1, rc = lc + 1;
        if (lc >= mSize) return true;
        if (mLess(mData[i], mData[lc])) return false;
        if (rc >= mSize) return true;
        if (mLess(mData[i], mData[rc])) return false;
    }
}

#endif