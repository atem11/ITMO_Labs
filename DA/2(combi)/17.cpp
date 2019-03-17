#include <bits/stdc++.h>

using namespace std;

long long dp[41][41];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("num2brackets.in", "r", stdin);
    //freopen("num2brackets.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    k++;
    n *= 2;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for(int j = 0; j <= n / 2; j++)
        {
            dp[i + 1][j + 1] += dp[i][j];
            if (j > 0) dp[i + 1][j - 1] += dp[i][j];
        }
    string ans = "";
    int bal = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i][bal + 1] >= k)
        {
            ans += "(";
            bal++;
        }
        else
        {
            ans += ")";
            k -= dp[i][bal + 1];
            bal--;
        }
    }
    cout << ans;
    return 0;
}
