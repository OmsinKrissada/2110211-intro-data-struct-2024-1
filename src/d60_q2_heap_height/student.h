#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>

#include <cmath>
#include <iostream>

#include "priority_queue.h"

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::height() const {
    // write your code here
    return size() ? log2(size()) : -1;
}

#endif
