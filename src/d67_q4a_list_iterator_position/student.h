#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
int CP::list<T>::data_iterator(CP::list<T>::iterator it) {
  // Write code here
  auto walk = begin();
  for (int i=0; i < mSize; i++) {
    if(walk == it) return i;
    walk++;
  }

  if (walk == it) return -1;
  return -2;
}

#endif
