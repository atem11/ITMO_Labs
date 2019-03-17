#include <bits/stdc++.h>

using namespace std;

int n;
double a;

bool func(double b)
{
    double x, y;
    bool f = true;
    x = a;
    y = b;
    for(int i = 2; i < n; i++)
    {
        double z = (y + (double)1) * (double)2 - x;
        x = y;
        y = z;
        if (y < 0.00001) f = false;
        if (!f) break;
    }
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    cin >> n >> a;
    double l = (double)0, r = (double)1e7;
    for (int i = 0; i < 200; i++)
    {
        double mid = (l + r) / 2;
        if (func(mid)) r = mid;
        else l = mid;
    }
    double x, y;
    x = a;
    y = l;
    for(int i = 2; i < n; i++)
    {
        double z = (y + (double)1) * (double)2 - x;
        x = y;
        y = z;
    }
    cout.precision(2);
    cout << fixed << y;
    return 0;
}
