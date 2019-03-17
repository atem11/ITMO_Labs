#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    int n;
    cin >> n;
    int mas[100001];
    bool f = true;
    for (int i = 1; i <= n; i++)
        cin >> mas[i];
    for (int i = 1; i <= n; i++)
    {
        if ((2 * i <= n && mas[i] > mas[2 * i]) || (2 * i + 1 <= n && mas[i] > mas[2 * i + 1])) f = false;
        if (!f) break;
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
