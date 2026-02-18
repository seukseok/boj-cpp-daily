#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> meetings(n); // {end, start}
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        meetings[i] = {end, start};
    }

    sort(meetings.begin(), meetings.end());

    int count = 0;
    int currentEnd = 0;

    for (const auto& [end, start] : meetings) {
        if (start >= currentEnd) {
            ++count;
            currentEnd = end;
        }
    }

    cout << count << '\n';
    return 0;
}
