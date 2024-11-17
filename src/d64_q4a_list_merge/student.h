#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>>& ls) {
    // write your code here
    for (auto it = ls.begin(); it != ls.end(); it++) {
        if (it->size() == 0) continue;
        auto& this_first = mHeader->next;
        auto& this_last = mHeader->prev;
        auto& that_first = it->mHeader->next;
        auto& that_last = it->mHeader->prev;

        this_last->next = that_first;
        that_first->prev = this_last;
        that_last->next = mHeader;
        mHeader->prev = that_last;

        it->mHeader->next = it->mHeader;
        it->mHeader->prev = it->mHeader;

        mSize += it->mSize;
        it->mSize = 0;
    }
}

#endif
