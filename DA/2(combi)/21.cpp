#include <bits/stdc++.h>

using namespace std;

long long dp[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("num2part.in", "r", stdin);
    freopen("num2part.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
        {
            if (i == j) dp[i][j] = 1;
            else
            {
                for (int l = j; l <= n; l++)
                    dp[i][j] += dp[i - j][l];
            }
        }
    /*for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }*/
    vector<int> ans;
    int uk = 1;
    for (int i = n; i > 0;)
    {
        while(k >= dp[i][uk])
        {
            k -= dp[i][uk];
            uk++;
        }
        i -= uk;
        ans.push_back(uk);
    }
    for (int i = 0; i < ans.size(); i++)
        if (i  != ans.size() - 1) cout << ans[i] << '+';
        else cout << ans[i];
    return 0;
}
