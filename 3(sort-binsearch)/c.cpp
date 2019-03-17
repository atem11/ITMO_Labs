#include <bits/stdc++.h>

using namespace std;

int *a;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int A, B, C, a1, a2;
    cin >> A >> B >> C >> a1 >> a2;
    a = new int[n];
    a[0] = a1;
    a[1] = a2;
    for (int i = 2; i < n; i++)
    {
        int val = A * a1 + B * a2 + C;
        a[i] = val;
        a1 = a2;
        a2 = val;
    }
    k--;
    for (int l = 0, r = n - 1; ; )
    {
        if (r <= l + 1)
        {
            if (r == l + 1 && a[r] < a[l])
                swap (a[l], a[r]);
            cout << a[k];
            return 0;
        }
        int mid = (l + r) >> 1;
        swap (a[mid], a[l + 1]);
        if (a[l] > a[r])
            swap (a[l], a[r]);
        if (a[l + 1] > a[r])
            swap (a[l + 1], a[r]);
        if (a[l] > a[l + 1])
            swap (a[l], a[l + 1]);
        int i = l + 1, j = r, cur = a[l + 1];
        for (;;)
        {
            while (a[++i] < cur) ;
            while (a[--j] > cur) ;
            if (i > j)
                break;
            swap (a[i], a[j]);
        }
        a[l + 1] = a[j];
        a[j] = cur;
        if (j >= k)
            r = j - 1;
        if (j <= k)
            l = i;
    }
    return 0;
}
