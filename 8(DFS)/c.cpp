#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int> > > g;
vector<int> win, use, topsort;
int N, M, S, T, Inf = 1e9 + 9;

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
    freopen("shortpath.in", "r", stdin);
    freopen("shortpath.out", "w", stdout);
    cin >> N >> M >> S >> T;
    g.resize(N);
    use.resize(N);
    win.resize(N);
    S--;
    T--;
    int u, v, m;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> m;
        g[u - 1].push_back({v - 1, m});
    }
    dfs(S);
    if (!use[T]) {
        cout << "Unreachable\n";
        return 0;
    }
    reverse(topsort.begin(), topsort.end());
    for (int i = 0; i < N; ++i) {
        win[i] = Inf;
    }
    win[S] = 0;
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
    cout << win[T] << '\n';
    return 0;
}

