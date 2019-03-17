#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n);
    int v, u, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
        g[v - 1].push_back({u - 1, w});
    }
    vector<int> ans(n, INF);
    ans[0] = 0;
    priority_queue<pair<int, int> > q;
    q.push({ans[0], 0});
    while (!q.empty()) {
        v = q.top().second;
        w = -q.top().first;
        q.pop();
        if (w > ans[v]) continue;
        for (size_t i = 0; i < g[v].size(); ++i) {
            u = g[v][i].first;
            w = g[v][i].second;
            if (ans[u] > ans[v] + w) {
                ans[u] = ans[v] + w;
                q.push({-ans[u], u});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}


