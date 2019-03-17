#include <bits/stdc++.h>

using namespace std;

long long dp[2001][2001];
long long rz[2001][2001], n, F[2001];
string ans[2001];

long long sum(int l, int r)
{
    if (l == 0)
        return F[r];
    else
        return F[r] - F[l - 1];
}

void makeans(int l, int r)
{
    if (l >= r)
        return;
    for (int i = l; i <= (int)rz[l][r]; i++)
        ans[i] += "0";
    for (int i = (int)rz[l][r] + 1; i <= r; i++)
        ans[i] += "1";
    makeans(l, (int)rz[l][r]);
    makeans((int)rz[l][r] + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("optimalcode.in", "r", stdin);
    freopen("optimalcode.out", "w", stdout);
    cin >> n;
    cin >> F[0];
    for (int i = 1; i < n; i++)
    {
        cin >> F[i];
        F[i] += F[i - 1];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0 ; j < n; j++)
            dp[i][j] = 1e18 + 7, rz[i][j] = -1;
    for (int i = 0; i < n; i++)
        dp[i][i] = 0, rz[i][i] = i;
    for (int len = 1; len < n; len++)
        for (int j = 0; j < n - len; j++)
        {
            for (int r1 = (int)rz[j][j + len - 1]; r1 <= rz[j + 1][j + len]; r1++)
            {
                if (dp[j][j + len] > dp[j][r1] + sum(j, j + len) + dp[r1 + 1][j + len])
                {
                    dp[j][j + len] = dp[j][r1] + sum(j, j + len) + dp[r1 + 1][j + len];
                    rz[j][j + len] = r1;
                }
            }
        }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }*/
    cout << dp[0][n - 1] << '\n';
    makeans(0, (int)n - 1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    return 0;
}

