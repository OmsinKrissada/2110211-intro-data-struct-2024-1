#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

namespace CP {

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::node_relation(iterator it1, iterator it2) {
    // Write code here
    node* parent = NULL;
    node* n1 = find_node((*it1).first, mRoot, parent);
    node* n2 = find_node((*it2).first, mRoot, parent);

    if (n1->parent == n2 || n2->parent == n1) {
        return 1;
    }

    node* walk = n1;
    while (walk != NULL) {
        if (walk == n2) return 2;
        walk = walk->parent;
    }
    walk = n2;
    while (walk != NULL) {
        if (walk == n1) return 2;
        walk = walk->parent;
    }

    int h1 = 0, h2 = 0;
    while (n1 != mRoot) {
        n1 = n1->parent;
        h1++;
    }
    while (n2 != mRoot) {
        n2 = n2->parent;
        h2++;
    }

    return h1 == h2 ? 4 : 3;
}

}

#endif
