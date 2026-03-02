#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    while (t--) {
        int l;
        cin >> l;

        int sx, sy, tx, ty;
        cin >> sx >> sy;
        cin >> tx >> ty;

        vector<vector<int>> dist(l, vector<int>(l, -1));
        queue<pair<int, int>> q;

        dist[sx][sy] = 0;
        q.push({sx, sy});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == tx && y == ty) break;

            for (int dir = 0; dir < 8; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        cout << dist[tx][ty] << '\n';
    }

    return 0;
}
