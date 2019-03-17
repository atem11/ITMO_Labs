#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    ans.resize(n, 1e9);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    ans[0] = 0;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for (size_t i = 0; i < g[u].size(); ++i) {
            v = g[u][i];
            if (ans[v] == 1e9) {
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
