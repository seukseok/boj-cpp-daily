#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);
    int components = 0;

    for (int start = 1; start <= N; ++start) {
        if (visited[start]) continue;

        components++;
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (visited[nxt]) continue;
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    cout << components << '\n';
    return 0;
}
