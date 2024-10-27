#include<bits/stdc++.h>
using namespace std;
bool isCycleDFS(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<bool>& reStack){
  if(!visited[u]){
    visited[u]=true;
    reStack[u]=true;
    for(int i: adj[u]){
      if(!visited[i] && isCycleDFS(adj,i,visited,reStack))
        return true;
      else if (reStack[i]){
        return true;
      }
        }
  }
  reStack[u] = false;
  return false;
}
bool isCyclic(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    // Call the recursive helper function to 
    // detect cycle in different DFS trees
    for (int i = 0; i < V; i++) {
        if (!visited[i] && 
            isCyclicUtil(adj, i, visited, recStack))
            return true;
    }

    return false;
}


int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);


    if (isCyclic(adj, V))
        cout << "Contains Cycle" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
