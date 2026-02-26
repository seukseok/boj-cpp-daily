#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        for (int cap = K; cap >= w; --cap) {
            dp[cap] = max(dp[cap], dp[cap - w] + v);
        }
    }

    cout << dp[K] << '\n';
    return 0;
}
