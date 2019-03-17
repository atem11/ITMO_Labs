#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("shooter.in", "r", stdin);
    freopen("shooter.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    double res, del = 0;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        x = 1.0 - x;
        if (i == k - 1)
        {
            res = pow(x, m);
        }
        del += pow(x, m);
    }
    cout.precision(13);
    cout << fixed << res / del;
    return 0;
}
