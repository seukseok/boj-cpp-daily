#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> dq;
        int num = 0;
        bool inNumber = false;
        for (char c : arr) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                inNumber = true;
            } else {
                if (inNumber) {
                    dq.push_back(num);
                    num = 0;
                    inNumber = false;
                }
            }
        }

        bool reversed = false;
        bool error = false;

        for (char op : p) {
            if (op == 'R') {
                reversed = !reversed;
            } else { // op == 'D'
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (!reversed) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (error) {
            cout << "error\n";
            continue;
        }

        cout << '[';
        if (!dq.empty()) {
            if (!reversed) {
                for (size_t i = 0; i < dq.size(); ++i) {
                    if (i) cout << ',';
                    cout << dq[i];
                }
            } else {
                for (int i = (int)dq.size() - 1; i >= 0; --i) {
                    if (i != (int)dq.size() - 1) cout << ',';
                    cout << dq[i];
                }
            }
        }
        cout << "]\n";
    }

    return 0;
}
