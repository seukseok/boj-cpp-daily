#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<long long> cables(k);
    long long hi = 0;
    for (int i = 0; i < k; ++i) {
        cin >> cables[i];
        hi = max(hi, cables[i]);
    }

    long long lo = 1;
    long long ans = 0;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;

        long long count = 0;
        for (long long len : cables) {
            count += len / mid;
        }

        if (count >= n) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
