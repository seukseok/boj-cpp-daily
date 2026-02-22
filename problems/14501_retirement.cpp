#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> T(N + 1), P(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    // dp[d]: d일이 끝났을 때 얻을 수 있는 최대 수익
    vector<int> dp(N + 2, 0);

    for (int day = 1; day <= N; day++) {
        // 오늘 상담을 안 하면 다음 날로 최대 수익을 넘긴다.
        dp[day + 1] = max(dp[day + 1], dp[day]);

        // 오늘 상담을 시작할 수 있는 경우
        int endDay = day + T[day];
        if (endDay <= N + 1) {
            dp[endDay] = max(dp[endDay], dp[day] + P[day]);
        }
    }

    cout << dp[N + 1] << '\n';
    return 0;
}
