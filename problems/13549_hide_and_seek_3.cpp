#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    const int MAX_POS = 100000;
    const int INF = 1e9;

    vector<int> dist(MAX_POS + 1, INF);
    deque<int> dq;

    dist[N] = 0;
    dq.push_back(N);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur == K) break;

        int nx = cur * 2;
        if (nx <= MAX_POS && dist[nx] > dist[cur]) {
            dist[nx] = dist[cur];
            dq.push_front(nx);
        }

        nx = cur - 1;
        if (nx >= 0 && dist[nx] > dist[cur] + 1) {
            dist[nx] = dist[cur] + 1;
            dq.push_back(nx);
        }

        nx = cur + 1;
        if (nx <= MAX_POS && dist[nx] > dist[cur] + 1) {
            dist[nx] = dist[cur] + 1;
            dq.push_back(nx);
        }
    }

    cout << dist[K] << '\n';
    return 0;
}
