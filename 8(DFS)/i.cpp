#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int> > g;
vector<int> used, tin, tout, ans, answ;
int tim;

void dfs(int v, int p = -1) {
    used[v] = 1;
    tim++;
    tin[v] = tim;
    tout[v] = tim;
    int kol = 0;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (u == p) {
            continue;
        }
        if (used[u]) {
            tout[v] = min(tout[v], tin[u]);
        } else {
            dfs(u, v);
            tout[v] = min(tout[v], tout[u]);
            if (tout[u] >= tin[v] && p != -1) {
                answ[v] = 1;
            }
            ++kol;
        }
    }
    if (p == -1 && kol > 1) {
        answ[v] = 1;
    }
}

int main() {
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    cin >> N >> M;
    int u, v;
    g.resize(N);
    used.resize(N);
    tout.resize(N);
    tin.resize(N);
    answ.resize(N);
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < N; ++i) {
        if (!used[i]) dfs(i);
    }
    for (int i = 0; i < N; ++i) {
        if (answ[i] != 0) ans.push_back(i + 1);
    }
    cout << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}



