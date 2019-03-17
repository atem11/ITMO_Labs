#include <bits/stdc++.h>

using namespace std;

long long dp[41][41];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("brackets2num.in", "r", stdin);
    freopen("brackets2num.out", "w", stdout);
    string s;
    cin >> s;
    long long n = s.size(), ans = 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for(int j = 0; j <= n / 2; j++)
        {
            dp[i + 1][j + 1] += dp[i][j];
            if (j > 0) dp[i + 1][j - 1] += dp[i][j];
        }
    int bal = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            bal++;
        }
        else
        {
            ans += dp[n - i - 1][bal + 1];
            bal--;
        }
    }
    cout << ans;
    return 0;
}

