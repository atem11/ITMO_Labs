#include <bits/stdc++.h>

using namespace std;

long long dp[43][43];

int n;

string gen(long long k)
{
    k++;
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
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("brackets2num2.in", "r", stdin);
    freopen("brackets2num2.out", "w", stdout);
    string s;
    cin >> s;
    n = s.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for(int j = 0; j <= n / 2; j++)
        {
            dp[i + 1][j + 1] += dp[i][j];
            if (j > 0) dp[i + 1][j - 1] += dp[i][j];
        }
    long long l = 0, r = dp[n][0] << (n / 2);
    while (r - l > 1)
    {
        long long mid = (l + r) >> 1;
        string m = gen(mid);
        if (m > s) r = mid;
        else
            l = mid;
    }
    cout << l;
    return 0;
}


