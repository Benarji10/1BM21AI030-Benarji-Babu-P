#include <iostream>
#include <climits>
using namespace std;

#define V 5

class MST {
private:
    int graph[V][V];
    int parent[V];
    int key[V];
    bool mstSet[V];

public:
    MST() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = 0;
            }
            parent[i] = -1;
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int minKey() {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++) {
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void printMST() {
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        }
    }

    void primMST() {
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++) {
            int u = minKey();
            mstSet[u] = true;
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
        printMST();
    }
};

int main() {
    MST mst;
    mst.addEdge(0, 1, 3);
    mst.addEdge(0, 3, 6);
    mst.addEdge(1, 2, 4);
    mst.addEdge(1, 3, 8);
    mst.addEdge(1, 4, 4);
    mst.addEdge(2, 3, 3);
    mst.addEdge(2, 4, 2);
    mst.addEdge(3, 4, 3);
    mst.primMST();

    return 0;
}
