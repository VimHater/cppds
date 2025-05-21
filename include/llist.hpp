#pragma once
#include <cstddef>
#include <memory>
namespace cppds {
template <class T>
class llist {
   public:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        Node(T value) : data(value), next(nullptr) {}
    };

    llist() : head(nullptr), tail(nullptr), size(0) {}
    ~llist() = default;

    void append(T x);
    void push_front(T x);
    void print();
    std::size_t get_size();
    Node *search_for(T x);

   private:
    std::unique_ptr<Node> head;
    Node *tail;
    std::size_t size;
};


}  // namespace cppds
//
#include "llist.ipp"
