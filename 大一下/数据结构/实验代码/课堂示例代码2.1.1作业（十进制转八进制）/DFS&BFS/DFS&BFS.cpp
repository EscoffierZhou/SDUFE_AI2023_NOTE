#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct Graph {
    vector<vector<int>> adjList;

    Graph(int n) {
        adjList.resize(n);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void bfs(int start) {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << "Visited node: " << current << endl;
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    cout << "Edge: " << current << " -> " << neighbor << endl;
                }
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(adjList.size(), false);
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();
            if (!visited[current]) {
                cout << "Visited node: " << current << endl;
                visited[current] = true;
                for (int neighbor : adjList[current]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                        cout << "Edge: " << current << " -> " << neighbor << endl;
                    }
                }
            }
        }
    }
};

int main() {
    int n = 4; // Number of vertices
    Graph g(n);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS traversal starting from vertex 2: " << endl;
    g.bfs(2);
    cout << endl;

    cout << "DFS traversal starting from vertex 2: " << endl;
    g.dfs(2);
    cout << endl;

    return 0;
}
