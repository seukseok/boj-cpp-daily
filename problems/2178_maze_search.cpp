#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 1;

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }
            if (grid[nr][nc] == '0' || dist[nr][nc] != 0) {
                continue;
            }

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    cout << dist[n - 1][m - 1] << '\n';
    return 0;
}
