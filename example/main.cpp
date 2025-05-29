#include <llist.hpp>
#include <stack.hpp>
#include <tree.hpp>
#include <queue.hpp>
#include <map.hpp>
#include <set.hpp>
#include <BST.hpp>
#include <Graph.hpp>
#include <unordered_set>
int main () {
    std::vector<int> vertices = {0, 1, 2, 3, 4, 5};
    cppds::Graph<int> gr(vertices);
    
    gr.add_edge(0, 1);
    gr.add_edge(0, 3);
    gr.add_edge(1, 3);
    gr.add_edge(2, 3);
    gr.add_edge(4, 5);

    std::unordered_set<int> BST = gr.BST(0);
    std::unordered_set<int> DFS = gr.DFS(0);

    for (auto node : BST) {
        std::cout << node << " ";
    }

    std::cout << std::endl;

    for (auto node : DFS) {
        std::cout << node << " ";
    }
}
