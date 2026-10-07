#include <iostream>
#include <vector>
#include <queue>

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

    void BFS(int start) {

        vector<bool> visited(V, false);

        queue<int> q;

        visited[start] = true;

        q.push(start);

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adj[current]) {

                if (!visited[neighbor]) {

                    visited[neighbor] = true;

                    q.push(neighbor);

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

    g.BFS(0);

}