#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        long long x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << prefix[j] - prefix[i - 1] << '\n';
    }

    return 0;
}
