#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> chars;
vector<char> picked;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void dfs(int idx, int cnt) {
    if (cnt == L) {
        int vowels = 0;
        for (char c : picked) {
            if (isVowel(c)) ++vowels;
        }
        int consonants = L - vowels;
        if (vowels >= 1 && consonants >= 2) {
            for (char c : picked) cout << c;
            cout << '\n';
        }
        return;
    }

    for (int i = idx; i < C; ++i) {
        picked.push_back(chars[i]);
        dfs(i + 1, cnt + 1);
        picked.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;
    chars.resize(C);
    for (int i = 0; i < C; ++i) cin >> chars[i];
    sort(chars.begin(), chars.end());

    dfs(0, 0);
    return 0;
}
