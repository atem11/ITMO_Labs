#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

bool Sf()
{
    bool f = 0;
    if (ans.size() == 1) f = 1;
    for (int i = 0; i < ans.size() / 2; i++)
        if (ans[i] == ans[ans.size() - i - 1]) f = 1;
    return f;
}

bool Mf()
{
    bool f = 0;
    int k = ans.size();
    for (int i = k / 2; i > 0; i /= 2)
    {
        for (int j = 0; j < k;)
        {
            int a = 0, b = 0;
            for (int i1 = j; i1 - j < i; i1++)
            {
                a *= 2;
                a += ans[i1];
            }
            j += i;
            for (int i1 = j; i1 - j < i; i1++)
            {
                b *= 2;
                b += ans[i1];
            }
            j += i;
            while (a > 0 || b > 0)
            {
                if (a % 2 > b % 2) f = 1;
                a = a >> 1;
                b = b >> 1;
            }
        }
    }
    return f;
}

bool Lf()
{
    bool f = 0;
    int k = ans.size();
    for (int i = 0; i < k; i++)
    {
        if (i != 0 && (i & (i - 1)) != 0 && ans[0] == 1) f = 1;
        for (int j = 0; j < k - i - 1; j++)
            ans[j] = ans[j] ^ ans[j + 1];
    }
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    bool T0 = 1, T1 = 1, S = 1, M = 1, L = 1;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        m = (1 << m);
        ans.resize(m);
        char x;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            if (x == '0') ans[j] = 0;
            else ans[j] = 1;
        }
        if (T0 && ans[0] != 0) T0 = 0;
        if (T1 && ans[m - 1] != 1) T1 = 0;
        if (S && Sf()) S = 0;
        if (M && Mf()) M = 0;
        if (L && Lf()) L = 0;
    }
    //cout << T0 << ' ' << T1 << ' ' << L << ' ' << M << ' ' << S << '\n';
    if (T0 || T1 || L || M || S) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
