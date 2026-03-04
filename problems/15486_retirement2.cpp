#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    vector<long long> dp(n + 2, 0);

    for (int day = 1; day <= n; day++) {
        dp[day] = max(dp[day], dp[day - 1]);

        int endDay = day + t[day] - 1;
        if (endDay <= n) {
            dp[endDay + 1] = max(dp[endDay + 1], dp[day] + p[day]);
        }
    }

    dp[n + 1] = max(dp[n + 1], dp[n]);
    cout << dp[n + 1] << '\n';

    return 0;
}
