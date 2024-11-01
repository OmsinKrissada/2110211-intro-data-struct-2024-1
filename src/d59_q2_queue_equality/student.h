#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
    if (mSize != other.mSize) return false;

    size_t la = mFront, lb = other.mFront;
    for (size_t i = 0; i < mSize; i++) {
        if (mData[la] != other.mData[lb]) return false;
        la = (la + 1) % mCap;
        lb = (lb + 1) % other.mCap;
    }
    return true;
}

#endif
