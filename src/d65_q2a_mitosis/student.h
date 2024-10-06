#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    size_t size = b - a + 1;
    size_t before = mSize - b - 1, after = a;

    size_t newCap = std::max(mSize + size, mCap * 2);
    if (mSize + size > mCap) expand(newCap);

    mSize += size;
    if (after)
        for (int i = after - 1; i >= 0; i--) {
            mData[before + 2 * size + i] = mData[before + size + i];
        }
    for (int i = size - 1; i >= 0; i--) {
        mData[before + 2 * i] = mData[before + i];
        mData[before + 2 * i + 1] = mData[before + i];
    }
}

#endif
