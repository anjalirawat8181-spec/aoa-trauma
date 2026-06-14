#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(vector<Edge>& edges, int vertices, int source) {
    vector<int> distance(vertices, INT_MAX);

    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < vertices; i++) {
        for (auto edge : edges) {
            if (distance[edge.source] != INT_MAX &&
                distance[edge.source] + edge.weight < distance[edge.destination]) {

                distance[edge.destination] =
                    distance[edge.source] + edge.weight;
            }
        }
    }

    // Check for negative weight cycle
    for (auto edge : edges) {
        if (distance[edge.source] != INT_MAX &&
            distance[edge.source] + edge.weight < distance[edge.destination]) {

            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main() {
    int vertices = 5;

    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, vertices, 0);

    return 0;
}