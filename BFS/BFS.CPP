#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int adjMatrix[10][10]; // Fixed-size adjacency matrix
    bool visited[10];       // Visited array
    int numVertices;


    Graph(int vertices) {
        numVertices = vertices;
        // Initialize adjacency matrix and visited array
        for (int i = 1; i <= numVertices; i++) {
            visited[i] = false;
            for (int j = 1; j <= numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void inputGraph() {
        cout << "\nEnter graph values in the form of an adjacency matrix:\n";
        for (int i = 1; i <= numVertices; i++) {
            for (int j = 1; j <= numVertices; j++) {
                cin >> adjMatrix[i][j];
            }
        }
    }

    void breadthFirstSearch(int startVertex) {
        queue<int> bfsQueue;
        visited[startVertex] = true;
        bfsQueue.push(startVertex);

        cout << "\nThe nodes which are reachable are:\n";

        while (!bfsQueue.empty()) {
            int vertex = bfsQueue.front();
            bfsQueue.pop();
            cout << vertex << "\t";

            for (int i = 1; i <= numVertices; i++) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    bfsQueue.push(i);
                }
            }
        }
    }
};

int main() {
    int n, startVertex;

    cout << "\nEnter the number of vertices: ";
    cin >> n;

    Graph graph(n);
    graph.inputGraph();

    cout << "\nEnter the source node: ";
    cin >> startVertex;

    graph.breadthFirstSearch(startVertex);

    return 0;
}

