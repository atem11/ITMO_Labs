#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int d[200][200];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n);
    int v, u, w;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = INF;
            if (i == j) d[i][i] = 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        d[u - 1][v - 1] = w;
    }
    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                d[j][i] = min(d[j][i], d[j][k] + d[k][i]);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}


