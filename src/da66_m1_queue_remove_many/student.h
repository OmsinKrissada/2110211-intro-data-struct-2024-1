#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos) {
    // your code here
    std::sort(pos.begin(), pos.end());
    size_t shift = 1;
    size_t currPos = 1;
    for (int i = pos[0]; i + shift < mSize; i++) {
        while (currPos < pos.size() && i + shift == pos[currPos]) {
            shift++;
            currPos++;
        }
        mData[(i + mFront) % mCap] = mData[(i + shift + mFront) % mCap];
    }

    mSize -= pos.size();
}

#endif
