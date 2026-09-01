#include <iostream>
#include <vector>


void DFS(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int node) {
    visited[node] = true;
    std::cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(graph, visited, neighbor);
        }
    }
}
int main() {
    int vertices = 5;
    std::vector<std::vector<int>> graph(vertices);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1};
    graph[4] = {1};

    std::vector<bool> visited(vertices, false);

    std::cout << "DFS starting from node 0: ";
    DFS(graph, visited, 0);
    std::cout << std::endl;

    return 0;
}