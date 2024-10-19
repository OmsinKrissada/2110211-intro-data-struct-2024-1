#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include <algorithm>

#include "vector.h"

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
    // Write code here
    std::sort(ranges.begin(), ranges.end());

    vector<T> nv;  // note: no move assignment operator

    iterator nf = begin();
    size_t nt = 0;
    for (std::pair<iterator, iterator> &r : ranges) {
        if (r.first > nf) {
            size_t newSize = nv.mSize + r.first - nf;
            nv.ensureCapacity(newSize);
            nv.mSize = newSize;
            std::copy(nf, r.first, nv.mData + nt);
            nt += r.first - nf;
#ifdef DEBUG
            std::cout << "ignore from " << nf - begin() << " to " << r.first - 1 - begin() << std::endl;
#endif
        }

        if (r.second > nf) {
            nf = r.second;
        }
    }
    size_t lastSize = nv.mSize + end() - nf;
    nv.ensureCapacity(lastSize);
    nv.mSize = lastSize;
    std::copy(nf, end(), nv.mData + nt);

    std::swap(this->mSize, nv.mSize);
    std::swap(this->mCap, nv.mCap);
    std::swap(this->mData, nv.mData);
}

#endif
