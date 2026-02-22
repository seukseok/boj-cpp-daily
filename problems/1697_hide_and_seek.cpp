#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    const int MAX = 100000;
    vector<int> dist(MAX + 1, -1);
    queue<int> q;

    dist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            cout << dist[cur] << '\n';
            return 0;
        }

        int nextPos[3] = {cur - 1, cur + 1, cur * 2};
        for (int nx : nextPos) {
            if (nx < 0 || nx > MAX) continue;
            if (dist[nx] != -1) continue;
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

    return 0;
}
