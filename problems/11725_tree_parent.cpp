#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> parent(n + 1, 0);
    queue<int> q;
    q.push(1);
    parent[1] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (parent[nxt] != 0) continue;
            parent[nxt] = cur;
            q.push(nxt);
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}
