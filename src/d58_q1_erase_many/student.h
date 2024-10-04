#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    for (auto it = pos.crbegin(); it != pos.crend(); it++) {
        erase(begin() + *it);
    }
}

#endif
