#include <bits/stdc++.h>

using namespace std;

int g[20][20], dp[270000][20];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("salesman.in", "r", stdin);
    freopen("salesman.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        x--;
        y--;
        g[x][y] = cost;
        g[y][x] = cost;
    }
    int msk = 1 << (n);

    for (int i = 0; i < msk; i++){
        for (int j = 0; j < n; j++)
            dp[i][j] = 2e9;
    }
    for (int j = 0; j < n; j++)
        dp[1 << j][j] = 0;

    for (int i = 0; i < msk; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                int ms = i ^ (1 << j);
                for (int v = 0; v < n; v++)
                {
                    if ((ms & (1 << v)) && g[v][j] != 0)
                        dp[i][j] = min(dp[i][j], dp[ms][v] + g[v][j]);
                }
            }
        }
    }
    int ans = 2e9;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[msk - 1][i]);
    if (ans == 2e9)
        cout << -1;
    else
        cout << ans;
    return 0;
}
