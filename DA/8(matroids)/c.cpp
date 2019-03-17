#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector< vector<int> > g;
bool used[1001];
vector<int> match, W;

void assig() {
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
}

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

bool comp(int a, int b) {
    return W[a] > W[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);//*/
    cin >> n;
    g.resize(n);
    match.assign(n, -1);
    assig();
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        W.push_back(w);
    }
    int u, v;
    vector<int> q;
    for (int i = 0; i < n; i++){
        q.push_back(i);
    }
    sort(q.begin(), q.end(), comp);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> u;
            u--;
            g[i].push_back(u);
        }
    }
    for (int i = 0; i < n; ++i) {
        assig();
        dfs(q[i]);
    }
    vector<int> ans;
    ans.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (match[i] != -1) {
            ans[match[i]] = i + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
