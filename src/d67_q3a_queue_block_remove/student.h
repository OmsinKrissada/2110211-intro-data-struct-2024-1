#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {
    // Write your code here
    size_t tail = mSize - to - 1;
    size_t head = from;

    if (tail < head) {
        for (int i = 0; i < tail; i++) {
            mData[(mFront + from + i) % mCap] = mData[(mFront + to + 1 + i) % mCap];
        }
    } else {
        for (int i = 0; i < head; i++) {
            mData[(mFront + to - i + mCap) % mCap] = mData[(mFront + from - 1 - i + mCap) % mCap];
        }
        mFront = (mFront + (to - from + 1)) % mCap;
    }

    mSize -= to - from + 1;

    return;
}
#endif