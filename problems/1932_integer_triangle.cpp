#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> triangle(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    dp[1][1] = triangle[1][1];

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }

    int answer = 0;
    for (int j = 1; j <= n; ++j) {
        answer = max(answer, dp[n][j]);
    }

    cout << answer << '\n';
    return 0;
}
