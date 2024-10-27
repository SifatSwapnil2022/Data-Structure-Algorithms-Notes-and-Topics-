#include <iostream>
#include <vector>
#include <list>

using namespace std;

void DFS(int v, int dest, vector<bool>& visited, vector<int>& path, const list<int>* adj) {
    visited[v] = true;
    path.push_back(v);

    if (v == dest) {
        for (int node : path)
            cout << node << " ";
        cout << endl;
    } else {
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFS(neighbor, dest, visited, path, adj);
            }
        }
    }

    path.pop_back();
    visited[v] = false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    list<int>* adj = new list<int>[V];

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int start, dest;
    cout << "Enter start and destination vertices: ";
    cin >> start >> dest;

    vector<bool> visited(V, false);
    vector<int> path;

    cout << "All paths from " << start << " to " << dest << ":\n";
    DFS(start, dest, visited, path, adj);

   
    return 0;
}
