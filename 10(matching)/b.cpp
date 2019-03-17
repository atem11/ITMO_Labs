#include <bits/stdc++.h>

using namespace std;

int n, m;
vector< vector<int> > g;
bool used[1000];
vector<int> match, math;

void assig() {
    for (int i = 0; i < 1000; ++i) {
        used[i] = false;
    }
}

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

void dfsup(int v) {
    used[v] = true;
    if (!used[match[v]] && match[v] != -1) dfsup(match[v]);
}

void dfsdown(int v) {
    used[v] = true;
    if (!used[math[v]] && math[v] != -1) dfsdown(math[v]);
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("paths.in", "r", stdin);
    freopen("paths.out", "w", stdout);//*/
    cin >> n >> m;
    g.resize(n);
    match.assign(n, -1);
    math.assign(n, -1);
    assig();
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        assig();
        dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        u = match[i];
        if (u != -1) {
            math[u] = i;
        }
    }
    assig();
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfsup(i);
            dfsdown(i);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
