#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
    std::vector<T> res;
    // write your code only here
    res.reserve(k);
    for (int i = 0; i < k; i++) res.push_back(mData[(mFront + i) % mCap]);
    return res;
}

template <typename T>
CP::queue<T>::queue(iterator from, iterator to) {
    // write your code only here
    size_t size = mCap = mSize = to - from;
    mFront = 0;
    mData = new T[size];
    std::copy(from, to, mData);
}

#endif
