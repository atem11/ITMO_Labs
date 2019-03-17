#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > dg;
vector<pair<int, int> > ed;
vector<pair<double, double> > ans;
vector<int> cycle, mod;
bool f = true;

void dfs(int v, int c) {
    mod[v] = c;
    if (!f) return;
    for (size_t i = 0; i < dg[v].size(); ++i) {
        if (mod[dg[v][i]] == 0) {
            dfs(dg[v][i], c * (-1));
        } else if (c == mod[dg[v][i]]) {
            f = false;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    cycle.resize(n);
    ans.resize(m);
    mod.assign(m, 0);
    dg.resize(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        ed.push_back({u, v});
    }
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        v--;
        cycle[v] = i;
    }
    for (int i = 0; i < m; i++) {
        int u = ed[i].first, v = ed[i].second;
        int cu = cycle[u], cv = cycle[v];
        if (abs(cu - cv) == 1) {
            ans[i].first = ((double)cu + cv) / 2;
            ans[i].second = (double)0;
        } else {
            ans[i].first = ((double)cu + cv) / 2;
            ans[i].second = ans[i].first - min(cu, cv);
        }
    }
    for (int i = 0 ; i < m; ++i) {
        int u = ed[i].first, v = ed[i].second;
        int cu = min(cycle[u], cycle[v]), cv = max(cycle[u], cycle[v]);
        for (int j = i + 1; j < m; ++j) {
            int a = ed[j].first, b = ed[j].second;
            int ca = min(cycle[a], cycle[b]), cb = max(cycle[a], cycle[b]);
            if ((cu < ca && ca < cv && cv < cb) || (ca < cu && cu < cb && cb < cv)) {
                dg[i].push_back(j);
                dg[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (mod[i] == 0) {
            dfs(i, 1);
        }
    }
    if (!f) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << cycle[i] << ' ' << 0 << ' ';
        }
        cout << '\n';
        for (int i = 0; i < m; i++) {
            cout << ans[i].first << ' ' << ans[i].second * mod[i] << '\n';
        }
    }
    return 0;
}
