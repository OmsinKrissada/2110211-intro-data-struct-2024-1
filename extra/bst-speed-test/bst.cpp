#pragma once

#include <cstddef>

template <typename T>
class Bst {
    std::size_t mSize = 0;

    class node {
        T data;
        node *parent, *left, *right;

        T &operator*() {
            return data;
        }
    };

    node *root;

    // Bst() {
    // }
    bool exist(T x) {
        if (root == nullptr) return false;
        node current = root;
        while (true) {
            if (current == x) return true;
            if (current < x) current = root->left;
            current = root->right;
        }
    }

   public:
    size_t size() const {
        return mSize;
    }

    node begin() const {
        return root;
    }
};