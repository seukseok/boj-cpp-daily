#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> dist(n - 1), cost(n);
    for (int i = 0; i < n - 1; ++i) cin >> dist[i];
    for (int i = 0; i < n; ++i) cin >> cost[i];

    long long minCost = cost[0];
    long long answer = 0;

    for (int i = 0; i < n - 1; ++i) {
        minCost = min(minCost, cost[i]);
        answer += minCost * dist[i];
    }

    cout << answer << '\n';
    return 0;
}
