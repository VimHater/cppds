#include <llist.hpp>
#include <stack.hpp>
#include <tree.hpp>
#include <queue.hpp>
#include <map.hpp>
#include <set.hpp>
#include <BST.hpp>

int main () {
    cppds::BST<int> binarySearchTree;
    binarySearchTree.insert(30);
    binarySearchTree.insert(20);
    binarySearchTree.insert(15);
    binarySearchTree.insert(50);
    binarySearchTree.print(2);
}
