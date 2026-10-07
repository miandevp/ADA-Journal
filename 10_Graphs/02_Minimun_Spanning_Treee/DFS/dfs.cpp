#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {

private:
    int V;
    vector<vector<int>> adj;

public:

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // quitar si es dirigido
    }

    void DFS(int start) {

        vector<bool> visited(V, false);

        stack<int> s;

        s.push(start);

        while (!s.empty()) {

            int current = s.top();
            s.pop();

            if (!visited[current]) {

                visited[current] = true;

                cout << current << " ";

                // Recorremos los vecinos al revés
                for (int i = adj[current].size() - 1; i >= 0; i--) {

                    int neighbor = adj[current][i];

                    if (!visited[neighbor]) {

                        s.push(neighbor);

                    }

                }

            }

        }

    }

};

int main() {

    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    g.DFS(0);

}