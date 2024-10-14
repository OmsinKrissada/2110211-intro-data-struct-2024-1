#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last) {
    // write your code here
    size_t start = mSize - std::min(mSize - 1, last) - 1;
    size_t stop = mSize - std::min(first, mSize - 1) - 1;
    if (stop <= start) return;
    for (size_t i = start; i <= start + (stop - start + 1) / 2 - 1; i++) {
        std::swap(mData[i], mData[stop - (i - start)]);
    }
}

#endif
