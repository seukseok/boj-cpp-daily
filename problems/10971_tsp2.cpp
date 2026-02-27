#include <bits/stdc++.h>
using namespace std;

int N;
int W[11][11];
bool visited[11];
int answer = INT_MAX;

void dfs(int start, int cur, int depth, int cost) {
    if (cost >= answer) return;

    if (depth == N) {
        if (W[cur][start] != 0) {
            answer = min(answer, cost + W[cur][start]);
        }
        return;
    }

    for (int nxt = 0; nxt < N; ++nxt) {
        if (visited[nxt] || W[cur][nxt] == 0) continue;
        visited[nxt] = true;
        dfs(start, nxt, depth + 1, cost + W[cur][nxt]);
        visited[nxt] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    for (int start = 0; start < N; ++start) {
        memset(visited, false, sizeof(visited));
        visited[start] = true;
        dfs(start, start, 1, 0);
    }

    cout << answer << '\n';
    return 0;
}
