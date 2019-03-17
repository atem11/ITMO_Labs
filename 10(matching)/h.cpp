#include <bits/stdc++.h>

using namespace std;

struct edge {
    size_t ind;
    int v;
};

int n, m;
vector<vector<edge> > g;
vector<int> st, fake;
vector<int> ans;
stack<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("paths.in", "r", stdin);
    freopen("paths.out", "w", stdout);//*/
    cin >> n >> m;
    g.resize(n);
    st.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        st[u]++; st[v]++;
        edge x;
        size_t a = g[v].size(), b = g[u].size();
        x.v = v;
        x.ind = a;
        g[u].push_back(x);
        x.v = u;
        x.ind = b;
        g[v].push_back(x);
    }
    int s = -1, ANS = 0;
    fake.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (st[i] % 2 == 1) {
            if (s == -1) {
                s = i;
                ANS++;
            } else {
                edge x;
                size_t a = g[i].size(), b = g[s].size();
                x.v = i;
                x.ind = a;
                g[s].push_back(x);
                x.v = s;
                x.ind = b;
                g[i].push_back(x);
                fake[s] = i;
                fake[i] = s;
                s = -1;
            }
        }
    }
    cout << max(1, ANS) << '\n';
    q.push(0);
    while (!q.empty()) {
        int v = q.top();
        while (g[v].size()) {
             edge u = g[v][g[v].size() - 1];
             g[v].pop_back();
             if (u.v != -1) {
                if (u.ind < g[u.v].size()) g[u.v][u.ind].v = -1;
                q.push(u.v);
                break;
             }
        }
        if (v == q.top()) {
            q.pop();
            ans.push_back(v);
        }
    }
    /*for (int i = 0; i < fake.size(); ++i) {
        cout << i << ' ' << fake[i] << '\n';
    }//*/
    if (ANS != 0) ans.pop_back();
    st.assign(ans.size(), 0);
    s = 0;
    for (size_t i = 0; i + 1 < ans.size(); ++i) {
        if (fake[ans[i]] == ans[i + 1]) {
            s = (int)i + 1;
            fake[ans[i + 1]] = -1;
            fake[ans[i]] = -1;
            break;
        }
    }
    for (size_t i = 0; i < st.size(); ++i) {
        st[i] = ans[(s + i) % st.size()];
    }

    for (size_t i = 0; i < ans.size(); ++i) {
        cout << st[i] + 1 << ' ';
        if (i + 1 < ans.size() && fake[st[i]] == st[i + 1]) {
            cout << '\n';
            fake[st[i + 1]] = -1;
            fake[st[i]] = -1;
        }
    }
    return 0;
}

