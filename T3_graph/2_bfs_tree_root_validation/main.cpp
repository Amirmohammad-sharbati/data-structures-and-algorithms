#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Graph and visited array as global variables
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1);

    // Read graph input
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Check for the highest valid root
    for (int root = n; root >= 1; root--) {
        // Reset visited array
        fill(visited.begin(), visited.end(), false);

        // Start BFS
        queue<int> q;
        q.push(root);
        visited[root] = true;
        bool valid = true;

        while (!q.empty() && valid) {
            int current_size = q.size();
            int degree = graph[q.front()].size(); // Degree of the first node at this level

            for (int i = 0; i < current_size; i++) {
                int node = q.front();
                q.pop();

                // Check if all nodes at this level have the same degree
                if (graph[node].size() != degree) {
                    valid = false;
                    break;
                }

                // Process neighbors
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }

        if (valid) {
            cout << root;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
