#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
bool found = false;

void dfs(int cur, int depth) {
    if (found) return;
    if (depth == 5) {
        found = true;
        return;
    }

    for (int nxt : graph[cur]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;
        dfs(nxt, depth + 1);
        visited[nxt] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.assign(N, {});
    visited.assign(N, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
        if (found) break;
    }

    cout << (found ? 1 : 0) << '\n';
    return 0;
}
