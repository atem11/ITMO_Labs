#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int main () {
    ///*
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    //*/
    string s;
    cin >> s;
    ans.resize(s.length());
    for (size_t i = 1; i < s.length(); ++i) {
        int mb = ans[i - 1];
        while (mb > 0 && s[i] != s[mb]) {
            mb = ans[mb - 1];
        }
        if (s[i] == s[mb]) {
            ++mb;
        }
        ans[i] = mb;
    }
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
