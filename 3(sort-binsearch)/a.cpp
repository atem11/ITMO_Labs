#include <bits/stdc++.h>

using namespace std;

int *a;

void quick(int l, int r)
{
    int v = rand();
    v %= (r - l + 1);
    v += l;
    int x = a[v];
    int i = l;
    int j = r;
    while(i <= j)
    {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(i < r)
        quick(i, r);
    if(l < j)
        quick(l, j);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quick(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}
