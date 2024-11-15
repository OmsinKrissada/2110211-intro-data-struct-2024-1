#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <stack>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t level, size_t tmp, std::vector<KeyT>& v) {
    // i prefer loop over recursion
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT, MappedT, CompareT>::at_level(size_t level) {
    // write your code here
    std::vector<KeyT> v;
    std::stack<std::pair<node*, size_t>> s;
    s.push(std::make_pair(mRoot, 0));
    while (!s.empty()) {
        auto [n, depth] = s.top();
        s.pop();

        if (depth == level) {
            v.push_back(n->data.first);
            continue;
        }
        if (n->left != NULL) s.push(std::make_pair(n->left, depth + 1));
        if (n->right != NULL) s.push(std::make_pair(n->right, depth + 1));
    }
    return v;
}

#endif
