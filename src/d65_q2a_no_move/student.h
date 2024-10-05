#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
    // your code here
    auto pos = std::upper_bound(aux.begin(), aux.end(), idx);
    auto outer_idx = pos - aux.begin();
    return *(mData[outer_idx].end() - (*pos - idx));
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
    // your code here
    // you MAY need this function
    size_t prev_size = aux.size() == 0 ? 0 : aux.back();
    aux.push_back(prev_size + mData.back().size());
}

#endif
