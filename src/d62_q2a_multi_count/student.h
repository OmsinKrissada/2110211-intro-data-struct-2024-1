#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <unordered_map>

#define DEBUG

#ifdef DEBUG
int allocationCount = 0;
void *operator new(size_t size) {
    allocationCount++;
    return malloc(size);
}
#endif

template <typename T>
std::vector<std::pair<T, size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    // write your code here
    std::unordered_map<T, size_t> m;
    for (auto &e : k) m[e] = 0;
    for (size_t i = 0; i < mSize; i++) {
        auto found = m.find(mData[mFront + i]);
        if (found == m.end()) continue;
        found->second++;
    }
    std::vector<std::pair<T, size_t>> v;
    v.reserve(k.size());
    for (auto &e : k) {
        v.emplace_back(e, m[e]);
    }
    return v;
}

#endif
