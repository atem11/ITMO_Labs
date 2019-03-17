#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> ans;
    int kol = 1;
    for (int i = 0; i < n; i++)
        kol *= 3;
    ans.resize(kol);
    for (int i = 0; i < kol; i += 3)
    {
        ans[i] += "0";
        ans[i + 1] += "1";
        ans[i + 2] += "2";
    }
    int step = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < kol;)
        {
            for (int k = 0; k < step; k++)
            {
                ans[j] += "0";
                ans[j + 1] += "1";
                ans[j + 2] += "2";
                j += 3;
            }
            for (int k = 0; k < step; k++)
            {
                ans[j] += "1";
                ans[j + 1] += "2";
                ans[j + 2] += "0";
                j += 3;
            }
            for (int k = 0; k < step; k++)
            {
                ans[j] += "2";
                ans[j + 1] += "0";
                ans[j + 2] += "1";
                j += 3;
            }
        }
        step *= 3;
    }
    for (int i = 0; i < kol; i++)
        cout << ans[i] << '\n';
    return 0;
}

