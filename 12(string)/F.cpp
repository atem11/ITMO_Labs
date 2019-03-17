#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int main () {
    //*
    freopen("period.in", "r", stdin);
    freopen("period.out", "w", stdout);
    //*/
    string s;
    cin >> s;
    ans.resize(s.length());
    int l = 0, r = 0, n = (int)s.length();
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            ans[i] = min(r - i + 1, ans[i - l]);
        }
        while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]]) {
            ++ans[i];
        }
        if (i + ans[i] - 1 > r) {
            r = i + ans[i] - 1;
            l = i;
        }
    }
    int answer = (int)s.size();
    for (size_t i = 1; i < ans.size(); ++i) {
        if  (ans[i] == (int)(ans.size() - i) && ans.size() % i == 0) {
            answer = (int)i;
            break;
        }
    }
    cout << answer;
    return 0;
}


