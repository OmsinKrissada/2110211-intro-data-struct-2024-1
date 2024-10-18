#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>

#include <cmath>
#include <iostream>

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::find(T k) const {
    // your code here
    size_t checkpoint = 2;
    T maxPerLevel = mData[0];
    for (size_t i = 0; i < mSize; i++) {
        if (mLess(maxPerLevel, mData[i])) maxPerLevel = mData[i];
        if (mData[i] == k) return true;
        if (i == checkpoint) {
            if (mLess(maxPerLevel, k)) return false;
            maxPerLevel = mData[i + 1];
            checkpoint = (checkpoint + 1) * 2;
        }
    }
    return false;
}

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::find_level(T k) const {
    // your code here
    int maxDepth = -1;
    size_t checkpoint = 2;
    T maxPerLevel = mData[0];
    for (size_t i = 0; i < mSize; i++) {
        if (mLess(maxPerLevel, mData[i])) maxPerLevel = mData[i];
        if (mData[i] == k) maxDepth = log2(i + 1);
        if (i == checkpoint) {
            if (mLess(maxPerLevel, k)) break;
            maxPerLevel = mData[i + 1];
            checkpoint = (checkpoint + 1) * 2;
        }
    }
    return maxDepth;
}

#endif
