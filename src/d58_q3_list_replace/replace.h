void replace(const T& x, CP::list<T>& y) {
    // write your code here
    auto now = y.begin();
    auto it = begin();
    while (it != end()) {
        if (*it == x) {
            it = erase(it);
            for (auto ity = y.begin(); ity != y.end(); ity++) {
                insert(it, *ity);
            }
        } else
            it++;
    }
}
