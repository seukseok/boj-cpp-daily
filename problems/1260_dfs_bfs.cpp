#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(N + 1, false);

    function<void(int)> dfs = [&](int cur) {
        visited[cur] = true;
        cout << cur << ' ';
        for (int nxt : graph[cur]) {
            if (!visited[nxt]) dfs(nxt);
        }
    };

    dfs(V);
    cout << '\n';

    fill(visited.begin(), visited.end(), false);
    queue<int> q;
    q.push(V);
    visited[V] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int nxt : graph[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    return 0;
}
