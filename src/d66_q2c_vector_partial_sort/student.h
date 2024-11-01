#ifndef __STUDENT_H_
#define __STUDENT_H_

// can include anything
#include <algorithm>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos, CompareT comp) {
    // Write code here
    // you can compare two data A and B of type T by calling comp(A,B)
    // which return true when A is less than B
    sort(pos.begin(), pos.end());
    std::vector<T> buffer;
    buffer.reserve(pos.size());
    for (auto &e : pos) {
        buffer.push_back(*e);
    }
    std::sort(buffer.begin(), buffer.end(), comp);

    auto nb = buffer.begin();
    for (auto &e : pos) {
        *e = *nb++;
    }
}

#endif
