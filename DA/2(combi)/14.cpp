#include <bits/stdc++.h>

using namespace std;

bool use[20];
long long fact[19], ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    fact[0] = 1;
    for (int i = 1; i <= 18; i++)
        fact[i] = fact[i - 1] * i;
    int n;
    cin >> n;
    for (int i = n - 1; i > 0; i--)
    {
        int x;
        cin >> x;
        long long kol = 0;
        use[x] = 1;
        for (int j = 1; j < x; j++)
            if (!use[j]) kol++;
        ans += kol * fact[i];
    }
    cout <<  ans << '\n';
    return 0;
}

