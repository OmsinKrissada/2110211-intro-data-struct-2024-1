#include "queue.h"
#include "stack.h"

namespace CP {
template <typename T>
void stack<T>::appendStack(stack<T> s) {
    s.ensureCapacity(s.size() + mSize);
    std::copy(mData, mData + mSize, s.mData + s.size());
    s.mSize += mSize;

    (*this) = s;
}

template <typename T>
void stack<T>::appendQueue(queue<T> q) {
    stack<T> res;
    for (size_t i = 0; i < q.size(); i++) {
        res.push(q.mData[(q.mFront + (q.size() - i - 1)) % q.mCap]);
    }
    for (size_t i = 0; i < mSize; i++) {
        res.push(mData[i]);
    }
    (*this) = res;
}

template <typename T>
void queue<T>::appendStack(stack<T> s) {
    while (!s.empty()) {
        push(s.top());
        s.pop();
    }
}

template <typename T>
void queue<T>::appendQueue(queue<T> q) {
    while (!q.empty()) {
        push(q.front());
        q.pop();
    }
}
}  // namespace CP
