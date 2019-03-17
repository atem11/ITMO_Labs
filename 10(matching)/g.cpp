#include <bits/stdc++.h>

using namespace std;

int n, edge[1001][1001];
vector<stack<int> > g;
vector<int> ans;
stack<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("euler.in", "r", stdin);
    freopen("euler.out", "w", stdout);//*/
    cin >> n;
    int st = 0, f = 0;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int k, u;
        cin >> k;
        if (k % 2 == 1) {
            st = i;
            f++;
        }
        for (int j = 0; j < k; ++j) {
            cin >> u;
            g[i].push(u - 1);
            edge[i][u - 1]++;
        }
    }
    if (f > 2) {
        cout << -1 << '\n';
        return 0;
    }
    q.push(st);
    while (!q.empty()) {
        int v = q.top();
        while (!g[v].empty()) {
             int u = g[v].top();
             g[v].pop();
             if (edge[v][u] > 0) {
                q.push(u);
                edge[v][u]--;
                edge[u][v]--;
                break;
             }
        }
        if (v == q.top()) {
            q.pop();
            ans.push_back(v + 1);
        }
    }
    cout << ans.size() - 1 << '\n';
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
