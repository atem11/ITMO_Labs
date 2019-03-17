#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nextmultiperm.in", "r", stdin);
    freopen("nextmultiperm.out", "w", stdout);
    int n;
    cin >> n;
    int ans[n];
    for (int i = 0; i < n; i++)
        cin >> ans[i];
    int ma = ans[n - 1];
    int uk = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (ans[i] < ma)
        {
            uk = i;
            break;
        }
        else
            ma = ans[i];
    }
    int uk2 = 0;
    if (uk == -1)
        for (int i = 0; i < n; i++)
            cout << 0 << ' ';
    else
    {
        int ma = 1e7;
        for (int i = uk + 1; i < n; i++)
            if (ans[i] < ma && ans[i] > ans[uk]) uk2 = i, ma = ans[i];
        swap(ans[uk], ans[uk2]);
        sort(ans + uk + 1, ans + n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
    }
    return 0;
}
