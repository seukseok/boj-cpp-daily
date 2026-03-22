#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int pictureCount = 0;
    int maxArea = 0;

    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 0 || visited[i][j]) continue;

            pictureCount++;
            int area = 0;

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                area++;

                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (visited[nx][ny] || board[nx][ny] == 0) continue;

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            maxArea = max(maxArea, area);
        }
    }

    cout << pictureCount << '\n' << maxArea << '\n';
    return 0;
}
