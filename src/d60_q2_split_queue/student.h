#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <iostream>
#include <stdexcept>
// #pragma once
#include <queue>
#include <vector>

#include "queue.h"

template <typename T>
std::vector<CP::queue<T> > CP::queue<T>::split_queue(int k) {
    std::vector<CP::queue<T> > qs(k);
    size_t initialSize = mSize;
    for (int i = 0; i < initialSize; i++) {
        qs[i % k].push(front());
        pop();
    }
    return qs;
}

#endif
