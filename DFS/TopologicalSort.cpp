#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void topologicalSortDFS(int vertex, vector<vector<int>>& adjacency, vector<bool>& visited, stack<int>& stack) {
    visited[vertex] = true;
    for (int i : adjacency[vertex]) {
        if (!visited[i]) {
            topologicalSortDFS(i, adjacency, visited, stack);
        }
    }
    stack.push(vertex);
}

void topologicalSort(vector<vector<int>>& adj, int v) {
    stack<int> st;
    vector<bool> visited(v, false);
    
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, adj, visited, st);
        }
    }
    
    while (!st.empty()) {
        cout << st.top() << " "; // Corrected here
        st.pop();
    }
    cout << endl;
}

int main() {
    int v = 6; // Number of vertices
    vector<vector<int>> adj(v);
    
    // Sample directed graph (DAG)
    // 5 -> 2, 5 -> 0, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    topologicalSort(adj, v);
    
    return 0;
}
