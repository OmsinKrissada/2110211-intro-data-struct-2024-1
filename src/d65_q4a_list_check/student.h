#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
bool CP::list<T>::check() {
    // your code here
    if (mSize > 0 && mHeader == NULL) return false;
    if (mSize == 0) return mHeader == NULL;
    node* n = mHeader;

    size_t s = mSize;
    while (s--) {
        n = n->next;
        if (n == NULL || n == mHeader || n->prev == NULL || n->prev->next != n) return false;
    }
    n = n->next;
    if (n == NULL || n != mHeader || n->prev == NULL || n->prev->next != n) return false;

    return true;
}

#endif
