#include <bits/stdc++.h>
using namespace std;

int R, C, T;
vector<vector<int>> room;
int upCleaner = -1, downCleaner = -1;

void spreadDust() {
    vector<vector<int>> add(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (room[i][j] <= 0) continue;
            int amount = room[i][j] / 5;
            if (amount == 0) continue;

            int cnt = 0;
            const int di[4] = {-1, 1, 0, 0};
            const int dj[4] = {0, 0, -1, 1};

            for (int d = 0; d < 4; ++d) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                if (room[ni][nj] == -1) continue;
                add[ni][nj] += amount;
                cnt++;
            }

            room[i][j] -= amount * cnt;
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (room[i][j] == -1) continue;
            room[i][j] += add[i][j];
        }
    }
}

void runCleaner() {
    // upper (counter-clockwise)
    for (int i = upCleaner - 1; i > 0; --i) room[i][0] = room[i - 1][0];
    for (int j = 0; j < C - 1; ++j) room[0][j] = room[0][j + 1];
    for (int i = 0; i < upCleaner; ++i) room[i][C - 1] = room[i + 1][C - 1];
    for (int j = C - 1; j > 1; --j) room[upCleaner][j] = room[upCleaner][j - 1];
    room[upCleaner][1] = 0;

    // lower (clockwise)
    for (int i = downCleaner + 1; i < R - 1; ++i) room[i][0] = room[i + 1][0];
    for (int j = 0; j < C - 1; ++j) room[R - 1][j] = room[R - 1][j + 1];
    for (int i = R - 1; i > downCleaner; --i) room[i][C - 1] = room[i - 1][C - 1];
    for (int j = C - 1; j > 1; --j) room[downCleaner][j] = room[downCleaner][j - 1];
    room[downCleaner][1] = 0;

    room[upCleaner][0] = -1;
    room[downCleaner][0] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> T;
    room.assign(R, vector<int>(C));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                if (upCleaner == -1) upCleaner = i;
                else downCleaner = i;
            }
        }
    }

    while (T--) {
        spreadDust();
        runCleaner();
    }

    int total = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (room[i][j] > 0) total += room[i][j];
        }
    }

    cout << total << '\n';
    return 0;
}
