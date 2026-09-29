#include <bits/stdc++.h>
using namespace std;

// ---------- Kruskal's Algorithm ----------
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mstWeight = 0;
    cout << "Kruskal's MST edges:\n";
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cout << e.u << " - " << e.v << " (" << e.w << ")\n";
            mstWeight += e.w;
        }
    }
    cout << "Total weight: " << mstWeight << "\n\n";
}

// ---------- Prim's Algorithm ----------
void primMST(int V, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int count = 0; count < V-1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        inMST[u] = true;
        for (auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    int mstWeight = 0;
    cout << "Prim's MST edges:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " (" << key[i] << ")\n";
        mstWeight += key[i];
    }
    cout << "Total weight: " << mstWeight << "\n";
}

// ---------- Driver Code ----------
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;
    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter each edge (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "\n--- Minimum Spanning Tree ---\n";
    kruskalMST(V, edges);
    primMST(V, adj);

    return 0;
}
