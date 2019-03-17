#include <bits/stdc++.h>

using namespace std;

const long long INF = 3e18;

vector<long long> ans;
vector<bool> use, use1;
vector<vector<int> > g1;

void dfs(int v) {
    use1[v] = true;
    for (size_t i = 0; i < g1[v].size(); ++i) {
        use[g1[v][i]] = true;
        if (!use1[g1[v][i]]) dfs(g1[v][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, s;
    cin >> n >> m >> s;
    vector<pair<pair<int, int>, long long> > g;
    ans.resize(n, INF);
    use.resize(n);
    use1.resize(n);
    g1.resize(n);
    int u, v;
    long long w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--; v--;
        g1[u].push_back(v);
        g.push_back({{u, v}, w});
    }
    ans[s - 1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            u = g[j].first.first;
            v = g[j].first.second;
            w = g[j].second;
            if (ans[u] < INF) {
                if (ans[v] > ans[u] + w && ans[v] > -INF) {
                    ans[v] = ans[u] + w;
                }
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        u = g[j].first.first;
        v = g[j].first.second;
        w = g[j].second;
        if (ans[u] < INF) {
            if (ans[v] > ans[u] + w) {
                ans[v] = ans[u] + w;
                use[v] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (use[i] && !use1[i]) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == INF) {
            cout << "*\n";
        } else if (use[i]) {
            cout << "-\n";
        } else {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}

