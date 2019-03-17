#include <bits/stdc++.h>

using namespace std;

long long dp[41][41];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("num2brackets2.in", "r", stdin);
    //freopen("num2brackets2.out", "w", stdout);
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
    stack<char> prov;
    for (int i = n - 1; i >= 0; i--)
    {
        long long kol = 0;
        if (bal + 1 <= n / 2) kol = dp[i][bal + 1] << ((i - bal - 1) / 2);
        if (kol >= k)
        {
            ans += "(";
            prov.push('(');
            bal++;
            continue;
        }
        k -= kol;
        kol = 0;
        if (prov.size() > 0 && prov.top() == '(' && bal - 1 >= 0)
                kol = dp[i][bal - 1] << ((i - bal + 1) / 2);
        if (kol >= k)
        {
            ans += ")";
            prov.pop();
            bal--;
            continue;
        }
        k -= kol;
        kol = 0;
        if (bal + 1 <= n / 2) kol = dp[i][bal + 1] << ((i - bal - 1) / 2);
        if (kol >= k)
        {
            ans += "[";
            prov.push('[');
            bal++;
            continue;
        }
        k -= kol;
        ans += "]";
        bal--;
        prov.pop();
    }
    cout << ans;
    return 0;
}
