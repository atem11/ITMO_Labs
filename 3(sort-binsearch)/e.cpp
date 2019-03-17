#include <bits/stdc++.h>

using namespace std;

string *a, *b;
int n, m, k;

void radix()
{
    int c[600];
    b = new string[n];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 600; j++)
            c[j] = 0;
        for (int j = 0; j < n; j++)
        {
            int d = int(a[j][m - i - 1]);
            c[d]++;
        }
        int cnt = 0;
        for (int j = 0; j < 600; j++)
        {
            int t = c[j];
            c[j] = cnt;
            cnt += t;
        }
        for (int j = 0; j < n; j++)
        {
            int d = int(a[j][m - i - 1]);
            b[c[d]] = a[j];
            c[d]++;
        }
        for (int j = 0; j < n; j++)
            a[j] = b[j];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    cin >> n >> m >> k;
    a = new string[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    radix();
    for (int i = 0; i < n; i++)
        cout << a[i] << '\n';
    return 0;
}
