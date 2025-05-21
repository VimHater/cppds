#pragma once
#include <iostream>
#include <llist.hpp>
#include <memory>
namespace cppds {

template <class T>
void llist<T>::append(T x) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(x);
    Node* new_node_r = new_node.get();

    if (!head) {
        head = std::move(new_node);
        tail = new_node_r;
    } else {
        tail->next = std::move(new_node);
        tail = new_node_r;
    }
    size++;
}

template <class T>
void llist<T>::push_front(T x) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(x);
    Node* new_node_r = new_node.get();

    if (!head) {
        tail = new_node_r;
    }
    new_node->next = std::move(head);
    head = std::move(new_node);
    size++;
}

template <class T>
std::size_t llist<T>::get_size() {
    return size;
}

template <class T>
typename llist<T>::Node* llist<T>::search_for(T x) {
    Node* current = head.get();
    while (current) {
        if (current->data == x) {
            return current;
        }
        current = current->next.get();
    }
    return nullptr;
}

template <class T>
void llist<T>::print() {
    Node* current = head.get();

    std::cout << "[";
    while (current) {
        std::cout << current->data;
        if (current->next) {
            std::cout << " -> ";
        }
        current = current->next.get();
    }
    std::cout << "]\n";

}
}  // namespace cppds
