#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int> > g;
vector<int> used, tin, tout, ans;
int tim, NUM;

void dfs(int v, int p = -1) {
    used[v] = 1;
    tin[v] = tim++;
    tout[v] = tim;
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
        }
    }
}

void dfs2(int v, int num) {
    ans[v] = num;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (ans[u] == 0) {
            if (tout[u] > tin[v]) {
                NUM++;
                dfs2(u, NUM);
            } else {
                dfs2(u, num);
            }
        }
    }
}

int main() {
    freopen("bicone.in", "r", stdin);
    freopen("bicone.out", "w", stdout);
    cin >> N >> M;
    int u, v;
    g.resize(N);
    used.resize(N);
    tout.resize(N);
    tin.resize(N);
    ans.resize(N);
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
        if (ans[i] == 0) {
            NUM++;
            dfs2(i, NUM);
        }
    }
    cout << NUM << '\n';
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}



