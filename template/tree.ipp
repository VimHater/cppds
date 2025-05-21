#pragma once

#include <iostream>
#include <sstream>
#include <tree.hpp>
namespace cppds {
template <class T>
void tree<T>::inorder_r(Node* root) {
    if (root != nullptr) {
        inorder_r(root->left);
        std::cout << root->x << " ";
        inorder_r(root->right);
    }
}

template <class T>
void tree<T>::preorder_r(Node* root) {
    if (root != nullptr) {
        std::cout << root->x << " ";
        preorder_r(root->left);
        preorder_r(root->right);
    }
}

template <class T>
void tree<T>::postorder_r(Node* root) {
    if (root != nullptr) {
        postorder_r(root->left);
        postorder_r(root->right);
        std::cout << root->x << " ";
    }
}

template <class T>
typename tree<T>::Node* tree<T>::search_r(Node* root, T _x) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->x == _x) {
        return root;
    }

    Node* left_r = search_r(root->left, _x);
    if (left_r != nullptr) {
        return left_r;
    }

    return search_r(root->right, _x);
}

template <class T>
typename tree<T>::Node* tree<T>::search(T _x) {
    return search_r(root, _x);
}

template <class T>
void tree<T>::inorder() {
    inorder_r(this->root);
}

template <class T>
void tree<T>::preorder() {
    preorder_r(this->root);
}

template <class T>
void tree<T>::postorder() {
    postorder_r(this->root);
}

template <class T>
void tree<T>::print(int width) {
    auto lines = build_tree_diagram(root, width);
    for (const auto& line : lines) {
        std::cout << line << '\n';
    }
}

template <class T>
std::vector<std::string> tree<T>::build_tree_diagram(typename tree<T>::Node* root,
                                            int& width) {
    if (!root) {
        width = 0;
        return {};
    }

    std::stringstream ss;
    ss << root->x;
    std::string root_str = ss.str();
    int root_width = root_str.length();

    int left_width = 0, right_width = 0;
    auto left_lines = build_tree_diagram(root->left, left_width);
    auto right_lines = build_tree_diagram(root->right, right_width);

    width = std::max(left_width + root_width + right_width, root_width);

    std::vector<std::string> result;

    std::string root_line(left_width, ' ');
    root_line += root_str;
    root_line += std::string(right_width, ' ');
    result.push_back(root_line);

    std::string branch_line(left_width, ' ');
    if (root->left)
        branch_line += '/';
    else
        branch_line += ' ';
    branch_line += std::string(root_width - 2 < 0 ? 0 : root_width - 2, ' ');
    if (root->right)
        branch_line += '\\';
    else
        branch_line += ' ';
    result.push_back(branch_line);

    size_t max_lines = std::max(left_lines.size(), right_lines.size());
    for (size_t i = 0; i < max_lines; ++i) {
        std::string left_part = (i < left_lines.size())
                                    ? left_lines[i]
                                    : std::string(left_width, ' ');
        std::string right_part = (i < right_lines.size())
                                     ? right_lines[i]
                                     : std::string(right_width, ' ');
        result.push_back(left_part + std::string(root_width, ' ') + right_part);
    }

    return result;
}

}  // namespace cppds
