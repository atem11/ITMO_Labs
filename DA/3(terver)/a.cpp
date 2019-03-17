#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    double res = 0;
    for (int i = 0; i < k; i++)
    {
        int p, m;
        cin >> p >> m;
        double a, b;
        a = (double) p / (double) n;
        b = (double) m / 100.0;
        res += a * b;
    }
    cout.precision(5);
    cout << fixed << res;
    return 0;
}
