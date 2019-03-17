#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int> > g, tg;
vector<int> used, topsort, ans;
int K = 1;

void topdfs(int v) {
    used[v] = 1;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (!used[u]) {
            topdfs(u);
        }
    }
    topsort.push_back(v);
}

void dfs(int v) {
    used[v] = 1;
    ans[v] = K;
    for (size_t i = 0; i < tg[v].size(); ++i) {
        int u = tg[v][i];
        if (!used[u]) dfs(u);
    }
}

int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    cin >> N >> M;
    int u, v;
    g.resize(N);
    tg.resize(N);
    used.resize(N);
    ans.resize(N);
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        tg[v].push_back(u);
    }
    for (int i = 0; i < N; ++i) {
        if (!used[i]) topdfs(i);
    }
    used.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        u = topsort[N - 1 - i];
        //cout << u << ' ';
        if (!used[u]) {
            dfs(u);
            K++;
        }
    }
    cout << K - 1 << '\n';
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
