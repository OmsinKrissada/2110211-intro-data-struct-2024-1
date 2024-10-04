#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  for (iterator this_it = mData; this_it != &mData[0] + mSize; this_it++)
    if (it == this_it) return true;
  return false;
}

#endif
