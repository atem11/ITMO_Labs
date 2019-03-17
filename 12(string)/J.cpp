#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int pref(string s) {
    ans.assign(s.length(), 0);
    int max1 = 0;
    for (size_t i = 1; i < s.length(); ++i) {
        int mb = ans[i - 1];
        while (mb > 0 && s[i] != s[mb]) {
            mb = ans[mb - 1];
        }
        if (s[i] == s[mb]) {
            ++mb;
        }
        if (mb > max1) {
            max1 = mb;
        }
        ans[i] = mb;
    }
    return max1;
}

int main () {
    //*
    freopen("keepcounted.in", "r", stdin);
    freopen("keepcounted.out", "w", stdout);
    //*/
    string s, t = "";
    cin >> s;
    long long ANS = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        t = s[i] + t;

        ANS += i + 1 - pref(t);
        cout << ANS << '\n';
    }
    return 0;
}
