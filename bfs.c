#include <iostream>
#include <queue>
using namespace std;

int main() {
    int graph[5][5] = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,1},
        {0,1,0,0,0},
        {0,1,1,0,0}
    };

    bool visited[5] = {false};
    queue<int> q;

    q.push(0);
    visited[0] = true;

    cout << "BFS Traversal: ";

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int i = 0; i < 5; i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}