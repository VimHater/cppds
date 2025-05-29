#pragma once
#include <vector>
#include <string>
namespace cppds {
template <class T>
class tree {
   protected:

    struct Node {
        T x;

        Node* left;
        Node* right;

        Node(T _x) : x(_x), left(nullptr), right(nullptr) {}
    };

    Node* root;


    virtual void inorder_r(Node* root);
    virtual void preorder_r(Node* root);
    virtual void postorder_r(Node* root);

    Node* delete_r(Node* root, T _x);

    Node* search_r(Node* root, T _x);

    virtual std::vector<std::string> build_tree_diagram(Node* root, int& width);
   public:
    tree() : root(nullptr) {};
    
    Node* search(T _x);
    virtual void inorder();
    virtual void preorder();
    virtual void postorder();
    virtual void print(int width);
};

}  // namespace cppds


#include "tree.ipp"
