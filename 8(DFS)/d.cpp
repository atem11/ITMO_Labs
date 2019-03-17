#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<int> win, use;
int N, M, S;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> N >> M >> S;
    g.resize(N);
    use.resize(N);
    win.resize(N);
    S--;
    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        use[u - 1] = 1;
        g[v - 1].push_back(u - 1);
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (!use[i]) q.push(i);
    }
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i];
            if (win[v] == 0) {
                q.push(v);
                win[v] = (win[u] + 1) % 2;
            }
        }
    }
    if (win[S] == 0) {
        cout << "Second player wins\n";
    } else {
        cout << "First player wins\n";
    }
    return 0;
}
