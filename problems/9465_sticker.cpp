#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> a(2, vector<int>(n + 1, 0));
        for (int row = 0; row < 2; row++) {
            for (int col = 1; col <= n; col++) {
                cin >> a[row][col];
            }
        }

        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        dp[0][1] = a[0][1];
        dp[1][1] = a[1][1];

        for (int i = 2; i <= n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + a[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + a[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }

    return 0;
}
