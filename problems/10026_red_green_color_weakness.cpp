#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> grid;
vector<vector<bool>> visited;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

bool sameColor(char a, char b, bool colorWeak) {
    if (!colorWeak) return a == b;
    if ((a == 'R' || a == 'G') && (b == 'R' || b == 'G')) return true;
    return a == b;
}

void bfs(int sr, int sc, bool colorWeak) {
    queue<pair<int,int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    char base = grid[sr][sc];

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (visited[nr][nc]) continue;
            if (!sameColor(base, grid[nr][nc], colorWeak)) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int countRegions(bool colorWeak) {
    visited.assign(n, vector<bool>(n, false));
    int regions = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (visited[r][c]) continue;
            bfs(r, c, colorWeak);
            regions++;
        }
    }
    return regions;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int normal = countRegions(false);
    int weak = countRegions(true);

    cout << normal << ' ' << weak << '\n';
    return 0;
}
