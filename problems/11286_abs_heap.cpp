#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(int a, int b) const {
        int aa = abs(a), bb = abs(b);
        if (aa == bb) return a > b;
        return aa > bb;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, Compare> pq;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}
