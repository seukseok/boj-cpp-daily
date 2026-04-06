#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    long long steps = 1; // 시작 수 포함 카운트
    while (B > A) {
        if (B % 10 == 1) {
            B /= 10;
            ++steps;
        } else if (B % 2 == 0) {
            B /= 2;
            ++steps;
        } else {
            break;
        }
    }

    if (B == A) cout << steps << '\n';
    else cout << -1 << '\n';

    return 0;
}
