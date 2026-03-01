#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> reachable(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> reachable[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (!reachable[i][k]) continue;
            for (int j = 0; j < N; ++j) {
                if (reachable[k][j]) {
                    reachable[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << reachable[i][j] << (j + 1 == N ? '\n' : ' ');
        }
    }

    return 0;
}
