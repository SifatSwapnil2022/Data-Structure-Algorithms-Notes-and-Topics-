#include<bits/stdc++.h>
using namespace std;

vector<list<int>> adj;
vector<bool> visited;

void insertEdges(int source , int destination){
  adj[source].push_back(destination);
}
void DFS(int vertex){
  visited[vertex] = true;
  cout<<vertex<< " ";

for(int n: adj[vertex]){
if(!visited[n]){
  DFS(n);
   }
  }
}

int main(){
  int vertex, edge;
cout<< "Enter the verterices ";
cin>>vertex;
adj.resize(vertex);
visited.resize(vertex,false);
cout<<"Enter the edges: "<<endl;
for(int i=0 ; i<edges ; i++){
int src,dest;
cin>>src>>dest;
insertEdge(src,dest);
}
cout<< " depth first traversal for the graph is : ";
DFS(0);
cout<<Endl;
return 0;
}
