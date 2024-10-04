#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <unordered_set>


template <typename T>
void CP::vector<T>::uniq() {
  std::unordered_set<T> s;
  CP::vector<T> new_v;
  for (size_t i = 0; i < mSize; i++) {
    if (!s.count(mData[i])) {
      new_v.push_back(mData[i]);
      s.insert(mData[i]);
    }
  }
  *this = new_v;
}

#endif
