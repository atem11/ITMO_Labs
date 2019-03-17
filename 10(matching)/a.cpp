#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector< vector<int> > g;
bool used[300];
vector<int> match;

void assig() {
    for (int i = 0; i < 300; ++i) {
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

int main() {
    ios_base::sync_with_stdio(0);
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);//*/
    cin >> n >> m >> k;
    g.resize(n);
    match.assign(m, -1);
    assig();
    int u, v;
    for (int i = 0; i < k; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        assig();
        bool f = dfs(i);
        if(f) ans++;
    }
    cout << ans << '\n';
    return 0;
}
