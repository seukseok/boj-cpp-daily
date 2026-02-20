#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    queue<tuple<int, int, int>> q;

    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                cin >> box[h][r][c];
                if (box[h][r][c] == 1) q.push({h, r, c});
            }
        }
    }

    const int dh[6] = {0, 0, 0, 0, 1, -1};
    const int dr[6] = {1, -1, 0, 0, 0, 0};
    const int dc[6] = {0, 0, 1, -1, 0, 0};

    while (!q.empty()) {
        auto [h, r, c] = q.front();
        q.pop();

        for (int d = 0; d < 6; ++d) {
            int nh = h + dh[d];
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nh < 0 || nh >= H || nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (box[nh][nr][nc] != 0) continue;

            box[nh][nr][nc] = box[h][r][c] + 1;
            q.push({nh, nr, nc});
        }
    }

    int days = 0;
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (box[h][r][c] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                days = max(days, box[h][r][c]);
            }
        }
    }

    cout << days - 1 << '\n';
    return 0;
}
