#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<int, int> > > g;
vector<int> used, tin, tout, ans, answ;
stack<int> a;
int tim, color;

void dfs(int v, int p = -1) {
    used[v] = 1;
    tim++;
    tin[v] = tim;
    tout[v] = tim;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i].first;
        int num = g[v][i].second;
        if (u == p) {
            continue;
        }
        if (!used[u]) {
            a.push(num);
            dfs(u, v);
            if (tout[u] >= tin[v]) {
                int col = color++;
                while (a.top() != num) {
                    answ[a.top()] = col;
                    a.pop();
                }
                answ[num] = col;
                a.pop();
            }
            if (tout[u] < tout[v]) tout[v] = tout[u];
            else if (tin[u] < tin[v]) a.push(num);
            else if (tout[v] > tin[u]) tout[v] = tout[u];
        }
    }
}

int main() {
    //freopen("biconv.in", "r", stdin);
    //freopen("biconv.out", "w", stdout);
    cin >> N >> M;
    int u, v;
    g.resize(N);
    used.resize(N);
    tout.resize(N);
    tin.resize(N);
    answ.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            tim = 0;
            color++;
            dfs(i);
        }
    }
    cout << color << '\n';
    for (int i = 0; i < M; ++i) {
        cout << answ[i] << ' ';
    }
    return 0;
}



