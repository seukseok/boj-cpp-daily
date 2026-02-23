#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    // (index, height) with strictly decreasing heights from bottom to top.
    stack<pair<int, int>> st;

    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top().second < h[i]) st.pop();

        if (st.empty()) ans[i] = 0;
        else ans[i] = st.top().first;

        st.push({i, h[i]});
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
