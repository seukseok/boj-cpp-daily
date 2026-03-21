#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> h(N);
    long long hi = 0;
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
        hi = max(hi, h[i]);
    }

    long long lo = 0;
    long long ans = 0;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long cut = 0;

        for (long long x : h) {
            if (x > mid) cut += (x - mid);
        }

        if (cut >= M) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
