#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const int MAXV = 10000;
    while (T--) {
        int A, B;
        cin >> A >> B;

        vector<int> prev(MAXV, -1);
        vector<char> op(MAXV, 0);
        vector<bool> visited(MAXV, false);

        queue<int> q;
        q.push(A);
        visited[A] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == B) break;

            int d = (cur * 2) % 10000;
            int s = (cur == 0) ? 9999 : cur - 1;
            int l = (cur % 1000) * 10 + (cur / 1000);
            int r = (cur / 10) + (cur % 10) * 1000;

            array<pair<int, char>, 4> nexts = {{{d, 'D'}, {s, 'S'}, {l, 'L'}, {r, 'R'}}};

            for (auto [nx, c] : nexts) {
                if (visited[nx]) continue;
                visited[nx] = true;
                prev[nx] = cur;
                op[nx] = c;
                q.push(nx);
            }
        }

        string ans;
        for (int x = B; x != A; x = prev[x]) {
            ans.push_back(op[x]);
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

    return 0;
}
