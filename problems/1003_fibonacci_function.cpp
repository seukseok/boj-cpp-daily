#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<pair<int, int>> dp(41);
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for (int i = 2; i <= 40; i++) {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }

    while (T--) {
        int n;
        cin >> n;
        cout << dp[n].first << ' ' << dp[n].second << '\n';
    }

    return 0;
}
