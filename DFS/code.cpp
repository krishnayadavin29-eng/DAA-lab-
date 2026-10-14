#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;  
    vector<vector<int>> adj;  

    void DFSUtil(int u, vector<bool>& visited, vector<int>& component) {
        visited[u] = true;
        component.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                DFSUtil(v, visited, component);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    void findConnectedComponents() {
        vector<bool> visited(V, false);
        int componentCount = 0;

        cout << "Connected Components:\n";
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                vector<int> component;
                DFSUtil(i, visited, component);
                
                componentCount++;
                cout << "Component " << componentCount << ": ";
                for (int node : component) {
                    cout << node << " ";
                }
                cout << "\n";
            }
        }
        cout << "Total number of connected components: " << componentCount << "\n";
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    
    g.addEdge(3, 4);

    g.findConnectedComponents();

    return 0;
}
