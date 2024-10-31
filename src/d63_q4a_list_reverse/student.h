#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
    // write your code here
    iterator prevA;
    iterator anchor = a;
    if (a == b) return a;
    b--;
    while (a != b && b != prevA) {
        prevA = a;
        std::swap(*a++, *b--);
    }
    return anchor;
}

#endif
