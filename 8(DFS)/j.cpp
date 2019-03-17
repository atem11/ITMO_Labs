#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int> > g;
vector<int> used;
bool f;

void dfs(int v, int c) {
    used[v] = c;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (used[u] == c) {
            f = true;
            return;
        }
        if (!used[u]) {
            dfs(u, c % 2 + 1);
        }
    }
}

int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    cin >> N >> M;
    int u, v;
    g.resize(N);
    used.resize(N);
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < N; ++i) {
        if (!used[i]) dfs(i, 1);
    }
    if (f) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}



