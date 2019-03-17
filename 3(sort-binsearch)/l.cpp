#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int u[N], w[N];
pair<double, int> mas[N], b[N];

void merg(int l, int r)
{
    int mid = (l + r) / 2;
    int uk1 = l, uk2 = mid + 1;
    for (int i = 0; i < r - l + 1; i++)
    {
        if (uk2 > r || (uk1 <= mid && mas[uk1].first < mas[uk2].first))
            b[i] = mas[uk1++];
        else
            b[i] = mas[uk2++];
    }
    for (int i = l; i <= r; i++)
    {
        mas[i] = b[i - l];
    }
}

void Merg(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) / 2;
    Merg(l, mid);
    Merg(mid + 1, r);
    merg(l, r);
}

int main()
{
    freopen("kbest.in", "r", stdin);
    freopen("kbest.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &u[i], &w[i]);
    }
    double l = 0, r = 1e7;
    for (int i1 = 0; i1 < 50; i1++)
    {
        double mid = (r + l) / 2;
        for (int i = 0; i < n; i++)
        {
            mas[i] = make_pair((double)u[i] - mid * w[i], i);
        }
        Merg(0, n - 1);
        double k1 = 0;
        for (int i = 0; i < k; i++)
        {
            k1 += mas[n - i - 1].first;
        }
        if (k1 >= 0) l = mid;
        else r = mid;
    }
    for (int i = 0; i < k; i++)
        printf("%d ", mas[n - i - 1].second + 1);
    return 0;
}
