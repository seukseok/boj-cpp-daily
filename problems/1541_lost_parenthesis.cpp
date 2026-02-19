#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string expr;
    cin >> expr;

    vector<int> nums;
    vector<char> ops;

    int current = 0;
    for (char ch : expr) {
        if (isdigit(ch)) {
            current = current * 10 + (ch - '0');
        } else {
            nums.push_back(current);
            ops.push_back(ch);
            current = 0;
        }
    }
    nums.push_back(current);

    int answer = nums[0];
    bool subtractMode = false;

    for (size_t i = 0; i < ops.size(); ++i) {
        if (ops[i] == '-') subtractMode = true;

        if (subtractMode) answer -= nums[i + 1];
        else answer += nums[i + 1];
    }

    cout << answer << '\n';
    return 0;
}
