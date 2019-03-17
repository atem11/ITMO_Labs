#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int main () {
    ///*
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
    //*/
    string p, t, s;
    cin >> p >> t;
    s = p + "#" + t;
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
    vector<size_t> incl;
    for (size_t i = p.length() + 1; i < ans.size(); ++i) {
        if (ans[i] == (int)p.size()) {
            size_t answ = i + 1 - 2 * p.size();
            incl.push_back(answ);
        }
    }
    cout << incl.size() << '\n';
    for (size_t i = 0; i < incl.size(); ++i) {
        cout << incl[i] << ' ';
    }
    return 0;
}

