#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
    size_t position_idx = position - begin();
    size_t section_size = last - first;

    ensureCapacity(mSize + section_size);
    mSize += section_size;

    iterator new_position = begin() + position_idx;
    // move existing data
    for (iterator it = end() - 1; it - section_size >= new_position; it--) {
        *it = *(it - section_size);
    }
    // do the actual insertion
    for (size_t i = 0; i < section_size; i++) {
        *(new_position + i) = *(first + i);
    }
}

#endif
