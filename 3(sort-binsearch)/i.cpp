#include <bits/stdc++.h>

using namespace std;

vector<long long> mas;

void quick(int l, int r)
{
    int v = rand();
    v %= (r - l + 1);
    v += l;
    long long x = mas[v];
    int i = l;
    int j = r;
    while(i <= j)
    {
        while(mas[i] < x) i++;
        while(mas[j] > x) j--;
        if(i <= j)
        {
            swap(mas[i], mas[j]);
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
    freopen("supermarket.in", "r", stdin);
    freopen("supermarket.out", "w", stdout);
    int n, m;
    long long k;
    cin >> n;
    long long min1 = 1e6;
    int kas[100000][3];
    for (int i = 0; i < n; i++)
    {
        cin >> kas[i][0] >> kas[i][1] >> kas[i][2];
        min1 = min(min1, (long long)(kas[i][1] + kas[i][2]));
    }
    cin >> m >> k;
    m = min(n, m);
    if (k == 0)
    {
        cout << 0;
        return 0;
    }
    long long l = min1 - 1, r = 2e10;
    while (r > l + 1)
    {
        long long k1 = 0;
        long long mid = (r + l) / 2;
        mas.resize(0);
        for (int i = 0; i < n; i++)
        {
            long long time = (long long)(kas[i][2] + kas[i][1]);
            if (time > mid) mas.push_back(0);
            else
            {
                time = mid - time;
                long long l1 = 0;
                if (kas[i][0] == 0) l1 = k;
                else l1 = time / (long long)kas[i][0];
                mas.push_back(l1);
            }
        }
        quick(0, n - 1);
        for (int i = 0; i < m; i++)
        {
            if (k1 >= k) break;
            k1 += mas[n - i - 1];
        }
        if (k1 >= k) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}
