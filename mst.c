#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[10];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unite(int a, int b) {
    parent[a] = b;
}

int main() {
    int n = 4, e = 5;

    Edge edges[] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    for(int i=0;i<n;i++)
        parent[i] = i;

    sort(edges, edges+e, compare);

    cout << "Edges in MST:\n";

    for(int i=0;i<e;i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b) {
            cout << edges[i].u << " - "
                 << edges[i].v << " = "
                 << edges[i].weight << endl;
            unite(a,b);
        }
    }
}