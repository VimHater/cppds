#pragma once
#include <tree.hpp>

#define Node typename tree<T>::Node

namespace cppds {
template <class T>
class BST : public tree<T> {
   public:
    void insert(T _x);

   private:
    Node* insert_r(Node* root, T _x);
};

}  // namespace cppds

#include <BST.ipp>
