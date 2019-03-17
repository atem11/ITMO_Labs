#include <bits/stdc++.h>

using namespace std;

bool use[32];
int cnk[32][32], ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("choose2num.in", "r", stdin);
    freopen("choose2num.out", "w", stdout);
    cnk[0][0] = 1;
    for (int i = 1; i < 32; i++)
        for (int j = 0; j <= i; j++)
            cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
    int n, k, prev = 0;
    int m = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        for (int j = prev + 1; j < x; j++)
            m += cnk[n - j][k - i];
        prev = x;
    }
    cout << m;
    return 0;
}



