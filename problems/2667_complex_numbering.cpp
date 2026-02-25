#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> board;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    board[sx][sy] = '0';

    int cnt = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != '1') continue;

            board[nx][ny] = '0';
            q.push({nx, ny});
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; ++i) cin >> board[i];

    vector<int> sizes;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '1') {
                sizes.push_back(bfs(i, j));
            }
        }
    }

    sort(sizes.begin(), sizes.end());
    cout << sizes.size() << '\n';
    for (int s : sizes) cout << s << '\n';

    return 0;
}
