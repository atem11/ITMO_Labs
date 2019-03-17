#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > ans;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int kol = 1;
    for (int i = 0; i < n; i++)
        kol *= k;
    ans.resize(kol);
    int step = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < kol;)
        {
            for (int el = 0; el < k; el++)
            {
                for (int l = 0; l < step; l++)
                {
                    if (j < kol) ans[j].push_back(el);
                    j++;
                }
            }
            for (int el = k - 1; el >= 0; el--)
            {
                for (int l = 0; l < step; l++)
                {
                    if (j < kol) ans[j].push_back(el);
                    j++;
                }
            }
        }
        step *= k;
    }
    for (int i = 0; i < kol; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << '\n';
    }
    return 0;
}


