#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start, target;
    cin >> start >> target;

    const long long INF = (long long)4e18;
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [curDist, cur] = pq.top();
        pq.pop();

        if (curDist != dist[cur]) continue;

        for (auto [next, cost] : graph[cur]) {
            long long nd = curDist + cost;
            if (nd < dist[next]) {
                dist[next] = nd;
                pq.push({nd, next});
            }
        }
    }

    cout << dist[target] << '\n';
    return 0;
}
