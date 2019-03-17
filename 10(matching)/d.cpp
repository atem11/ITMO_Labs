#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<int> > g;
bool used[1000];
vector<bool> useL, useR;
vector<int> match;

void assig() {
    for (int i = 0; i < 1000; ++i) {
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

void minpoint(int L) {
    if (L == -1) {
        return;
    }
    useL[L] = true;
    for (size_t i = 0; i < g[L].size(); ++i) {
        int u = g[L][i];
        if (match[u] != L && !useR[u]) {
            useR[u] = true;
            minpoint(match[u]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("birthday.in", "r", stdin);
    freopen("birthday.out", "w", stdout);//*/
    cin >> k;
    for (int ITER = 0; ITER < k; ++ITER) {
        cin >> n >> m;
        g.clear();
        g.resize(n);
        match.assign(m, -1);
        assig();
        int u;
        for (int i = 0; i < n; ++i) {
            vector<bool> us;
            us.assign(m, false);
            while (cin >> u) {
                if (u == 0) {
                    break;
                }
                us[u - 1] = true;
            }
            for (int j = 0; j < m; ++j) {
                if (!us[j]) {
                    g[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            assig();
            dfs(i);
        }
        vector<bool> us;
        us.assign(n, false);
        for (int i = 0; i < m; ++i) {
            if (match[i] != -1) {
                us[match[i]] = true;
            }
        }
        useL.assign(n, false);
        useR.assign(m, false);
        for (int i = 0; i < n; ++i) {
            if (!us[i] && !useL[i]) {
                minpoint(i);
            }
        }
        vector<int> ansL, ansR;
        for (int i = 0; i < n; ++i) {
            if (useL[i]) ansL.push_back(i + 1);
        }
        for (int i = 0; i < m; ++i) {
            if (!useR[i]) ansR.push_back(i + 1);
        }
        cout << ansL.size() + ansR.size() << '\n';
        cout << ansL.size() << ' ' << ansR.size() << '\n';
        for (size_t i = 0; i < ansL.size(); ++i) {
            cout << ansL[i] << ' ';
        }
        cout << '\n';
        for (size_t i = 0; i < ansR.size(); ++i) {
            cout << ansR[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

