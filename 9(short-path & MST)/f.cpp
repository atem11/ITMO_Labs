#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Node {
    int u, v;
    int w;
    Node(int u1, int v1, int w1) {
        u = u1;
        v = v1;
        w = w1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    int n, w;
    cin >> n;
    vector<Node> g;
    vector<int> ans(n, 0), p(n, -1);
    for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> w;
                if (w != INF) {
                    g.push_back(*(new Node(i, j, w)));
                }
            }
    }
    int m = (int)g.size();
    int u = -1;
    for (int i = 0; i < n; ++i) {
        u = -1;
        for (int j = 0; j < m; ++j) {
            if (ans[g[j].v] > ans[g[j].u] + g[j].w) {
                ans[g[j].v] = max(ans[g[j].u] + g[j].w, -INF);
                p[g[j].v] = g[j].u;
                u = g[j].v;
            }
        }
    }

    if (u == -1) {
        cout << "NO\n";
    } else {
        int v = u;
        for (int i = 0; i < n; ++i) {
            v = p[v];
        }
        vector<int> cycle;
        for(int i = v; ; i = p[i]) {
            cycle.push_back(i);
            if (i == v && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        cout << cycle.size() << '\n';
        for (size_t i = 0; i < cycle.size(); ++i) {
            cout << cycle[i] + 1 << ' ';
        }
    }
    return 0;
}

