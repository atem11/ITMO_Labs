#include <bits/stdc++.h>

using namespace std;

struct node {
    int next[26];
    bool term;
    int p;
    int pch;
    bool be;
    int suf_link;
    vector<int> ind_ans;

    node() {
        for (int i = 0; i < 26; ++i) {
            next[i] = -1;
        }
        term = false;
        p = -1;
        pch = -1;
        suf_link = -1;
        be = false;
        ind_ans.resize(0);
    }

    ~node(){}
};

vector<node> t;

void add_str(string s, int k) {
    int v = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        int ind = (int)(s[i] - 'a');
        if (t[v].next[ind] == -1) {
            node x = *(new node());
            x.p = v;
            x.pch = ind;
            t[v].next[ind] = (int)t.size();
            t.push_back(x);
        }
        v = t[v].next[ind];
    }
    t[v].term = true;
    t[v].ind_ans.push_back(k);
}

int go(int v, int c);

int link(int v) {
    if (t[v].suf_link == -1) {
        if (v == 0 || t[v].p == 0) {
            t[v].suf_link = 0;
        } else {
            t[v].suf_link = go(link(t[v].p), t[v].pch);
        }
    }
    return t[v].suf_link;
}

int go(int v, int c) {
    if (t[v].next[c] == -1) {
        t[v].next[c] = (v == 0 ? 0 : go(link(v), c));
    }
    return t[v].next[c];
}

int main () {
    ios_base::sync_with_stdio(0);
    //*
    freopen("search4.in", "r", stdin);
    freopen("search4.out", "w", stdout);
    //*/
    node r = *(new node());
    t.push_back(r);
    int n;
    cin >> n;
    vector<bool> ans;
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ans[i] = false;
        add_str(s, i);
    }

    int k = -1;
    for (int i = 0; i < (int)t.size(); ++i) {
        k = link(i);
    }
    assert(k != -1);

    string txt;
    cin >> txt;
    int tmp = 0;
    for (int i = 0; i < (int)txt.size(); ++i) {
        int ch = (int)(txt[i] - 'a');
        tmp = go(tmp, ch);
        if (!t[tmp].be) {
            t[tmp].be = true;
            int v = tmp;
            while (v != 0) {
                if (t[v].term) {
                    for (size_t j = 0; j < t[v].ind_ans.size(); ++j) {
                        ans[t[v].ind_ans[j]] = true;
                    }
                }
                v = link(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
