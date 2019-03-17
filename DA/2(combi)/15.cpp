#include <bits/stdc++.h>

using namespace std;

bool use[32];
int cnk[32][32], ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
    cnk[0][0] = 1;
    for (int i = 1; i < 32; i++)
        for (int j = 0; j <= i; j++)
            cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
    /*for (int i = 1; i < 32; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << cnk[i][j] << ' ';
        cout << '\n';
    }*/

    int n, k, prev = 0;
    int m;
    cin >> n >> k >> m;
    m++;
    for (int i = 1; i <= k; i++)
    {
        for (int j = prev + 1; j <= n; j++)
        {
            //cout << i << ' ' << j << ' ' << cnk[n - j][k - i] << ' ' << m << '\n';
            if (cnk[n - j][k - i] < m) m -= cnk[n - j][k - i];
            else
            {
                cout << j << ' ';
                prev = j;
                break;
            }
        }
    }
    return 0;
}


