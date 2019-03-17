#include <bits/stdc++.h>

using namespace std;

bool use[100009];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int ans[k];
    for (int i = 0; i < k; i++)
        cin >> ans[i];
    int uk = -1, ch = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        if (ans[i] != n - ch)
        {
            uk = i;
            break;
        }
        ch++;
    }
    if (uk == -1)
        cout << uk;
    else
    {
        for (int i = 0; i < k; i++)
            use[ans[i]] = 1;
        for (int i = ans[uk] + 1; i <= n; i++)
            if (use[i] == 0)
            {
                ans[uk] = i;
                break;
            }
        for (int i = 0; i <= uk; i++)
            cout << ans[i] << ' ';
        ch = 0;
        for (int i = uk + 1; i < k; i++)
            ch++, cout << ans[uk] + ch << ' ';
    }
    return 0;
}
