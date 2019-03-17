#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e16;
vector<bool> use;
vector<vector<pair<int, long long> > > g;

int main() {
    ios_base::sync_with_stdio(0);
    int n, s, f;
    cin >> n >> s >> f;
    s--;  f--;
    g.resize(n);
    use.resize(n);
    int v, u;
    long long w;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w;
            if (i != j && w != -1) {
                g[i].push_back({j, w});
            }
        }
    }
    vector<long long> ans(n + 1, INF);
    ans[s] = 0;
    for(int k = 0; k < n; ++k) {
        v = n;
        for (int i = 0; i < n; ++i) {
            if (!use[i] && ans[i] < ans[v]) {
                v = i;
            }
        }
        if (ans[v] == INF) {
            break;
        }
        use[v] = true;
        for (size_t i = 0; i < g[v].size(); ++i) {
            u = g[v][i].first;
            w = g[v][i].second;
            if (ans[u] > ans[v] + w) {
                ans[u] = ans[v] + w;
            }
        }
    }
    if (ans[f] == INF) {
        cout << "-1\n";
    } else {
        cout << ans[f] << '\n';
    }
    return 0;
}

