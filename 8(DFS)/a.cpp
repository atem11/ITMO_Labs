#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<int> ans, use;
bool cycle;
int N, M;

void dfs(int v) {
    use[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int u = g[v][i];
        if (use[u] == 1 || cycle == true) {
            cycle = true;
            return;
        }
        if (use[u] == 0) {
            dfs(u);
        }
    }
    use[v] = 2;
    ans.push_back(v);
}

int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
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
            dfs(i);
        }
    }
    if (cycle) {
        cout << -1 << '\n';
    } else {
        for (int i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i] + 1 << ' ';
        }
    }
    return 0;
}
