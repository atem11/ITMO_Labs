#include <bits/stdc++.h>

using namespace std;

bool use[100009];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nextperm.in", "r", stdin);
    freopen("nextperm.out", "w", stdout);
    int n;
    cin >> n;
    int ma, mi;
    int ans[n];
    for (int i = 0; i < n; i++)
        cin >> ans[i];
    mi = ans[n - 1];
    int uk = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (ans[i] > mi)
        {
            uk = i;
            break;
        }
        else
        {
            mi = ans[i];
        }
    }
    if (uk == -1)
    {
        for (int i = 0; i < n; i++)
            cout << 0 << ' ';
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < uk; i++)
        {
            use[ans[i]] = 1;
            cout << ans[i] << ' ';
        }
        mi = 0;
        for (int i = uk; i < n; i++)
            if (ans[i] < ans[uk] && ans[i] > mi) mi = ans[i];
        use[mi] = 1;
        cout << mi << ' ';
        for (int i = n; i > 0; i--)
            if (use[i] == 0) cout << i << ' ';
        cout << '\n';
    }

    for (int i = 0; i <= n; i++)
        use[i] = 0;

    ma = ans[n - 1];
    uk = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (ans[i] < ma)
        {
            uk = i;
            break;
        }
        else
        {
            ma = ans[i];
        }
    }
    if (uk == -1)
    {
        for (int i = 0; i < n; i++)
            cout << 0 << ' ';
    }
    else
    {
        for (int i = 0; i < uk; i++)
        {
            use[ans[i]] = 1;
            cout << ans[i] << ' ';
        }
        ma = 1e9;
        for (int i = uk; i < n; i++)
            if (ans[i] > ans[uk] && ans[i] < ma) ma = ans[i];
        use[ma] = 1;
        cout << ma << ' ';
        for (int i = 1; i <= n; i++)
            if (use[i] == 0) cout << i << ' ';
    }
    return 0;
}
