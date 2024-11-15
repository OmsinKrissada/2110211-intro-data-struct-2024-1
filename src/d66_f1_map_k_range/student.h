#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>

#include "map_bst_lite.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, const KeyT &a, const KeyT &b, std::vector<MappedT> &result) const {
    // you MAY need to use this function
    bool cond = !mLess(n->data.first, a) && !mLess(b, n->data.first);  // n->data.first >= a && n->data.first <= b
    if (n->left == NULL) {
        if (cond) {
            result.push_back(n->data.second);
        }
    } else {
        my_recur(n->left, a, b, result);
        if (cond) {
            result.push_back(n->data.second);
        }
    }

    if (n->right != NULL) my_recur(n->right, a, b, result);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<MappedT> CP::map_bst<KeyT, MappedT, CompareT>::value_in_key_range(const KeyT &a, const KeyT &b) const {
    /* write your code here */
    std::vector<KeyT> v;
    node *n = mRoot;
    while (true) {
        if (mLess(a, n->data.first) && mLess(b, n->data.first))
            n = n->left;
        else if (mLess(n->data.first, a) && mLess(n->data.first, b))
            n = n->right;
        else
            break;
    }
    my_recur(n, a, b, v);
    return v;
}

#endif
