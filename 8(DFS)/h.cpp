#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<int, int> > > g;
vector<int> used, tin, tout, ans;
int tim;

void dfs(int v, int p = -1) {
    used[v] = 1;
    tin[v] = tim++;
    tout[v] = tim;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i].first;
        int num = g[v][i].second;
        if (u == p) {
            continue;
        }
        if (used[u]) {
            tout[v] = min(tout[v], tin[u]);
        } else {
            dfs(u, v);
            tout[v] = min(tout[v], tout[u]);
            if (tout[u] > tin[v]) {
                ans.push_back(num);
            }
        }
    }
}

int main() {
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
    cin >> N >> M;
    int u, v;
    g.resize(N);
    used.resize(N);
    tout.resize(N);
    tin.resize(N);
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back({v, i + 1});
        g[v].push_back({u, i + 1});
    }
    for (int i = 0; i < N; ++i) {
        if (!used[i]) dfs(i);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}


