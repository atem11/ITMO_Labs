#include <bits/stdc++.h>

using namespace std;

int p[2001], dp[2001][2001];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("salesman.in", "r", stdin);
    //freopen("salesman.out", "w", stdout);
    int n, mod = 1e9;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        dp[i][i] = 1;
    }
    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j];
            if (p[i] == p[j])
                dp[i][j]++;
            else
            {
                dp[i][j] -= dp[i + 1][j - 1];

            }
            dp[i][j] = dp[i][j] % mod;
            dp[i][j] += mod;
            dp[i][j] = dp[i][j] % mod;
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
