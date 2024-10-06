#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include <algorithm>

#include "stack.h"

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::split_stack(int k) const {
    // your code here
    // should return something
    std::vector<std::vector<T>> container;
    container.reserve(k);
    for (int i = 0; i < k; i++) {
        std::vector<T> section;
        for (int j = 0; mSize >= 1 + (i + j * k); j++) {
            section.push_back(mData[mSize - 1 - (i + j * k)]);
        }
        std::reverse(section.begin(), section.end());
        container.push_back(section);
    }
    return container;
}

#endif
