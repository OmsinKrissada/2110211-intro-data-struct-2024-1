#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include <algorithm>
#include <unordered_set>

#include "vector.h"

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
    std::sort(itrs.begin(), itrs.end());
    std::unordered_set<T> s;
    CP::vector<T> nV;
    nV.ensureCapacity(mSize);

    size_t shift = 0;
    size_t lookup = 0;
    for (auto it = begin(); it != end(); it++) {
        if (itrs[lookup] == it) {
            lookup++;
            if (!s.count(*it)) {
                nV.push_back(*it);
                s.insert(*it);
            }
        } else {
            nV.push_back(*it);
        }
    }

    *this = nV;
}

#endif