#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<int> ans, use;
bool cycle;
int N, M;

int dfs(int v, int f) {
    use[v] = 1;
    for (size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (use[u] == 0) {
            f = dfs(u, f);
        }
        if (f != -1) {
            if (f != u) ans.push_back(u);
            use[v] = 2;
            if (f != u) return f;
            else return -1;
        }
        if (use[u] == 1 && !cycle) {
            cycle = 1;
            ans.push_back(u);
            use[v] = 2;
            return u;
        }
    }
    use[v] = 2;
    return f;
}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    cin >> N >> M;
    g.resize(N);
    use.resize(N);
    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }
    for (int i = 0; i < N; i++) {
        if (use[i] == 0) {
            dfs(i, -1);
        }
    }
    if (!cycle) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (int i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i] + 1 << ' ';
        }
    }
    return 0;
}

