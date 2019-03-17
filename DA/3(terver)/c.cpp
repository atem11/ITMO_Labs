#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    double n;
    int m;
    cin >> n >> m;
    double res = 0;
    double t[m][2];
    for (int i = 0; i < m; i++)
    {
        cin >> t[i][0] >> t[i][1];
    }
    res += n * (1.0 - 1.0 / t[0][0]);
    double x = 1.0 / t[0][0];
    for (int i = 0; i < m - 1; i++)
    {
        res += (n - t[i][1]) * x * (1.0 - 1.0 / t[i + 1][0]);
        x *= (1.0 / t[i + 1][0]);
    }
    res += (n - t[m - 1][1]) * x;
    cout << res;
    return 0;
}
