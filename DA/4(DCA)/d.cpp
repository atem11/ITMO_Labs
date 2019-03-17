#include <bits/stdc++.h>

using namespace std;

int n, m, k, L;
vector<vector<int> > automat;
vector<int> ext;
int dp[100][1003], mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
    cin >> n >> m >> k >> L;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        dp[x][0] = 1;
        ext.push_back(x);
    }
    automat.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        automat[a].push_back(b);
    }
    for (int i = 1; i <= L; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < automat[j].size(); k++) {
                dp[j][i] += dp[automat[j][k]][i - 1];
                dp[j][i] %= mod;
            }
        }
    }
    cout << dp[0][L] << '\n';
    return 0;
}
