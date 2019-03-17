#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int> > > g;
vector<int> win, use, need, topsort;
int N, M, Inf = 1e9 + 9;

void dfs(int v) {
    use[v] = 1;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i].first;
        if (use[u] == 0) {
            dfs(u);
        }
    }
    topsort.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    cin >> N >> M;
    g.resize(N);
    use.resize(N);
    need.resize(N);
    win.resize(N);
    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        need[v - 1] = 1;
        g[u - 1].push_back({v - 1, -1});
    }
    int S = -1;
    for (int i = 0; i < N; ++i) {
        if (need[i] == 0) {
            if (S == -1) {
                S = i;
            } else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    dfs(S);
    reverse(topsort.begin(), topsort.end());
    for (int i = 0; i < N; ++i) {
        win[i] = Inf;
    }
    win[S] = 0;
    int m;
    for (size_t j = 0; j < topsort.size(); ++j) {
        u = topsort[j];
        for (size_t i = 0; i < g[u].size(); ++i) {
            v = g[u][i].first;
            m = g[u][i].second;
            if (win[v] > win[u] + m) {
                win[v] = win[u] + m;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (win[i] == -N + 1) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}


