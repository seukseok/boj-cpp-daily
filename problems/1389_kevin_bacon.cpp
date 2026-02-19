#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    const int INF = 1e9;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

    for (int i = 1; i <= N; ++i) dist[i][i] = 0;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int bestPerson = 1;
    int bestScore = INF;

    for (int i = 1; i <= N; ++i) {
        int score = 0;
        for (int j = 1; j <= N; ++j) score += dist[i][j];

        if (score < bestScore) {
            bestScore = score;
            bestPerson = i;
        }
    }

    cout << bestPerson << '\n';
    return 0;
}
