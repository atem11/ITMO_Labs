#include <bits/stdc++.h>

using namespace std;

long long dp[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("part2num.in", "r", stdin);
    freopen("part2num.out", "w", stdout);
    vector<int> str;
    int n = 0;
    char ch;
    int x;
    cin >> x;
    n += x;
    str.push_back(x);
    while (cin >> ch)
    {
        cin >> x;
        n += x;
        str.push_back(x);
    }
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
    long long ans = 0;
    int uk = n, uk2 = 1;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = uk2; j < str[i]; j++)
            ans += dp[uk][j];
        uk2 = str[i];
        uk -= str[i];
    }
    cout << ans;
    return 0;
}

