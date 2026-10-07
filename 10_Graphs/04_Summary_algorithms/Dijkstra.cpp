#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

void dijkstra(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size();

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Distancias desde el nodo " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Nodo " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int n = 8;
    vector<vector<Edge>> graph(n);

    auto addEdge = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
    };

    // Grafo del ejercicio
    addEdge(0, 1, 1); // A -> B
    addEdge(0, 4, 4); // A -> E
    addEdge(0, 5, 8); // A -> F

    addEdge(1, 2, 2); // B -> C
    addEdge(1, 5, 6); // B -> F
    addEdge(1, 6, 6); // B -> G

    addEdge(2, 3, 1); // C -> D
    addEdge(2, 6, 2); // C -> G

    addEdge(3, 6, 1); // D -> G
    addEdge(3, 7, 4); // D -> H

    addEdge(4, 5, 5); // E -> F

    addEdge(6, 5, 1); // G -> F
    addEdge(6, 7, 1); // G -> H

    dijkstra(0, graph); // Nodo A

    return 0;
}