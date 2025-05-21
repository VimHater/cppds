#pragma once

#include <BST.hpp>

#define Node typename tree<T>::Node

namespace cppds {

template <class T>
Node* BST<T>::insert_r(Node* root, T _x) {
    if (root == nullptr) {
        return new Node(_x);
    }

    if (_x < root->x) {
        root->left = insert_r(root->left, _x);
    }
    else {
        root->right = insert_r(root->right, _x);
    }

    return root;
}

template <class T>
void BST<T>::insert(T _x) {
    this->root = insert_r(this->root, _x);
}

}  // namespace cppds
