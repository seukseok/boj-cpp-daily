#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int x;
    cin >> x;

    sort(a.begin(), a.end());

    int left = 0, right = n - 1;
    int answer = 0;

    while (left < right) {
        int sum = a[left] + a[right];

        if (sum == x) {
            answer++;
            left++;
            right--;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << answer << '\n';
    return 0;
}
