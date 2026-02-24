#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> score(n + 1);
    for (int i = 1; i <= n; ++i) cin >> score[i];

    if (n == 1) {
        cout << score[1] << '\n';
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    for (int i = 3; i <= n; ++i) {
        // i-1을 밟는 경우: i-3 -> i-1 -> i
        // i-1을 건너뛰는 경우: i-2 -> i
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }

    cout << dp[n] << '\n';
    return 0;
}
