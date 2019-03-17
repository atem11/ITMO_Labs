#include <bits/stdc++.h>

using namespace std;

struct node {
    int next[26];
    bool term;
    int p;
    int pch;
    int counted;
    int suf_link;

    node() {
        for (int i = 0; i < 26; ++i) {
            next[i] = -1;
        }
        term = false;
        p = -1;
        pch = -1;
        suf_link = -1;
        counted = 0;
    }

    ~node(){}
};

vector<node> t;
vector<int>  mapp;

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
    mapp[k] = v;
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
    freopen("divljak.in", "r", stdin);
    freopen("divljak.out", "w", stdout);
    //*/
    node r = *(new node());
    t.push_back(r);
    int n;
    cin >> n;
    mapp.resize(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        add_str(s, i);
    }

    int k = -1;
    for (int i = 0; i < (int)t.size(); ++i) {
        k = link(i);
    }
    assert(k != -1);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int cmnd;
        cin >> cmnd;
        if (cmnd == 1) {
            string txt;
            cin >> txt;
            vector<bool> check;
            check.assign(t.size(), false);
            int tmp = 0;
            for (int j = 0; j < (int)txt.size(); ++j) {
                int ch = (int)(txt[j] - 'a');
                tmp = go(tmp, ch);
                int v = tmp;
                while (v != 0) {
                    if (t[v].term && !check[v]) {
                        t[v].counted++;
                        check[v] = true;
                    }
                    v = link(v);
                }
            }
        } else {
            int num;
            cin >> num;
            num--;
            int v = mapp[num];
            cout << t[v].counted << '\n';
        }
    }
    return 0;
}

