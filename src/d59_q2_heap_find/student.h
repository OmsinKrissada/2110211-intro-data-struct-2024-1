#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>

#include <iostream>
#include <stack>

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::find(T k) const {
    // your code here
    std::stack<T> buf;
    buf.push(0);
    while (!buf.empty()) {
        T idx = std::move(buf.top());
        buf.pop();
        if (mData[idx] == k) return true;
        T leftIdx = 2 * idx + 1, rightIdx = 2 * idx + 2;
        if (leftIdx > mSize - 1) continue;
        if (!mLess(mData[leftIdx], k)) buf.push(leftIdx);
        if (!mLess(mData[rightIdx], k)) buf.push(rightIdx);
    }
    return false;
}

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::find_level(T k) const {
    // your code here
    std::stack<std::pair<T, int>> buf;
    int maxDepth = -1;
    buf.push({0, 0});
    while (!buf.empty()) {
        auto p = std::move(buf.top());
        buf.pop();
        if (mData[p.first] == k) maxDepth = std::max(maxDepth, p.second);
        T leftIdx = 2 * p.first + 1, rightIdx = 2 * p.first + 2;
        if (leftIdx > mSize - 1) continue;
        if (!mLess(mData[leftIdx], k)) buf.push({leftIdx, p.second + 1});
        if (!mLess(mData[rightIdx], k)) buf.push({rightIdx, p.second + 1});
    }
    return maxDepth;
}

#endif
