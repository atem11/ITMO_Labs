#include <bits/stdc++.h>

using namespace std;

vector<int> ans, ans_rew;

vector<int> z_func(string s) {
    vector<int> _ans;
    _ans.resize(s.length());
    int l = 0, r = 0, n = (int)s.length();
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            _ans[i] = min(r - i + 1, _ans[i - l]);
        }
        while (i + _ans[i] < n && s[_ans[i]] == s[i + _ans[i]]) {
            ++_ans[i];
        }
        if (i + _ans[i] - 1 > r) {
            r = i + _ans[i] - 1;
            l = i;
        }
    }
    return _ans;
}

size_t new_ind(size_t i) {
    return ans.size() - i + 1;
}

int main () {
    //*
    freopen("search3.in", "r", stdin);
    freopen("search3.out", "w", stdout);
    //*/
    string p, t;
    cin >> p >> t;
    string s, s_rew, p_rew, t_rew;
    s = p + "#" + t;
    for (int i = (int)p.length() - 1; i >= 0; --i) {
        p_rew += p[i];
    }
    for (int i = (int)t.length() - 1; i >= 0; --i) {
        t_rew += t[i];
    }
    s_rew = p_rew + "#" + t_rew;
    ans = z_func(s);
    ans_rew = z_func(s_rew);
    vector<int> fnd;
    int len = (int)p.length();
    for (size_t i = p.length() + 1; i <= ans.size() - len; ++i) {
        if (ans[i] + ans_rew[new_ind(i)] >= len - 1) {
            //cout << ans[i] << '-' << i << ' ' << ans_rew[new_ind(i)] << '-' << new_ind(i) << '\n';
            fnd.push_back((int)i - len);
        }
    }
    cout << fnd.size() << '\n';
    for (size_t i = 0; i < fnd.size(); ++i) {
        cout << fnd[i] << ' ';
    }
    return 0;
}

