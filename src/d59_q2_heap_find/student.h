#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>

#include <cmath>
#include <iostream>

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::find(T k) const {
    // your code here
    for (size_t i = 0; i < mSize; i++) {
        if (mData[i] == k) return true;
    }
    return false;
}

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::find_level(T k) const {
    // your code here
    int maxDepth = -1;
    for (size_t i = 0; i < mSize; i++) {
        if (mData[i] == k) maxDepth = (int)log2(i + 1);
    }
    return maxDepth;
}

#endif
