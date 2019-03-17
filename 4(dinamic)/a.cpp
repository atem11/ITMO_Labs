#include <bits/stdc++.h>

using namespace std;

long long dp[402][402];
int rz[400][400], n, a[402], b[402];

void print(int l, int r)
{
    if (rz[l][r] == -1)
        for (int i = 0; i < r - l + 1; i++)
            cout << "A";
    else
    {
        int R = rz[l][r];
        bool f = 0, f1 = 0;
        if (R != l)
        {
            cout << '(';
            f = 1;
        }
        print(l, R);
        if (f) cout << ')';
        if (R + 1 != r)
        {
            cout << '(';
            f1 = 1;
        }
        print(R + 1, r);
        if (f1)
            cout << ')';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = 0 ; j < n; j++)
            dp[i][j] = 1e9 + 7, rz[i][j] = -1;
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int len = 1; len < n; len++)
        for (int j = 0; j < n - len; j++)
            for (int r1 = j; r1 < j + len + 1; r1++)
            {
                if (dp[j][j + len] > dp[j][r1] + a[j] * b[r1] * b[j + len] + dp[r1 + 1][j + len])
                {
                    dp[j][j + len] = dp[j][r1] + a[j] * b[r1] * b[j + len] + dp[r1 + 1][j + len];
                    rz[j][j + len] = r1;
                }
            }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << rz[i][j] << ' ';
        cout << '\n';
    }*/
    if (n > 1)
        cout << '(';
    print(0, n - 1);
    if (n > 1)
        cout << ')';
    return 0;
}
