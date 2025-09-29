#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const unsigned long long MOD = 1000000007;

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> one_neighbor(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> bfs_queue;
    vector<bool> visited(n + 1, false);

    vector<int> distance(n + 1, -1);
    vector<unsigned long long> path_count(n + 1, 0);

    bfs_queue.push(1);
    visited[1] = true;
    distance[1] = 0;
    path_count[1] = 1;

    while (!bfs_queue.empty()) {
        int head = bfs_queue.front();
        bfs_queue.pop();

        for (int neighbor: graph[head]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[head] + 1;
                path_count[neighbor] = path_count[head];
                bfs_queue.push(neighbor);
            } else if (distance[neighbor] == distance[head] + 1)
                path_count[neighbor] = (path_count[neighbor] + path_count[head]) % MOD;
        }
    }

    if (distance[n] == -1) cout << 0;
    else cout << path_count[n];

    return 0;
}
