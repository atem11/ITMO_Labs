#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int w[1000], c[1000], r[1001][10001];

void findans(int k, int s)
{
    if (r[k][s] == 0)
        return;
    if (r[k - 1][s] == r[k][s])
        findans(k - 1, s);
    else
    {
        findans(k - 1, s - w[k - 1]);
        ans.push_back(k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    int n, M;
    cin >> n >> M;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= M; j++)
        {
            if (j >= w[i - 1])
                r[i][j] = max(r[i - 1][j], r[i - 1][j - w[i - 1]] + c[i - 1]);
            else
                r[i][j] = r[i - 1][j];
        }
    findans(n, M);
    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}
