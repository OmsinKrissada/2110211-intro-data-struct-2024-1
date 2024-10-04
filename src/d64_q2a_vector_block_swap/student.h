#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
    if (m == 0) return false;
    if (a < begin() || a + m > end()) return false;
    if (b < begin() || b + m > end()) return false;
    if (a + m - 1 >= b && a < b + m - 1) return false;
    if (b + m - 1 >= a && b < a + m - 1) return false;

    for (size_t i = 0; i < m; i++) std::swap(a[i], b[i]);

    return true;
}

#endif
