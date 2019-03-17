#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
    int n;
    cin >> n;
    int mas[300004], p[300004], pr[300004], ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
        p[i] = -1;
        pr[i] = -1;
    }
    dp.push_back(-1e9-7);
    for (int i = 1; i <= n; i++)
        dp.push_back(1e9+7);
    for (int i = 0; i < n; i++)
    {
        int j = int (upper_bound (dp.begin(), dp.end(), mas[i]) - dp.begin());
        if (dp[j-1] < mas[i] && mas[i] < dp[j])
        {
            dp[j] = mas[i];
            p[j] = i;
            pr[i] = p[j - 1];
            ans = max(ans, j);
        }
    }
    cout << ans << '\n';
    vector<int> answer;
    int pred = p[ans];
    while (pred != -1)
    {
        answer.push_back(mas[pred]);
        pred = pr[pred];
    }
    for (int i = ans - 1; i >= 0; i--)
        cout << answer[i] << ' ';
    return 0;
}
