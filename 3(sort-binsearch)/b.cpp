#include <bits/stdc++.h>

using namespace std;

int *mas;
int n, m;

int up_search(int z)
{
    int l = 0, r = n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (mas[mid] > z) r = mid;
        else l = mid;
    }
    return l;
}

int down_search(int z)
{
    int l = 0, r = n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (mas[mid] >= z) r = mid;
        else l = mid;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    cin >> n;
    mas = new int[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int z;
        cin >> z;
        int r = up_search(z), l = down_search(z);
        if (mas[r] == z) r++;
        else r = -1;
        if (mas[l] == z) l++;
        else
            if(l + 1 < n && mas[l + 1] == z) l += 2;
            else l = -1;
        cout << l << ' ' << r << '\n';
    }
    return 0;
}
