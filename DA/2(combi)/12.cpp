#include <bits/stdc++.h>

using namespace std;

int n, k;

void gen(int x, vector<vector<int> > ans)
{
    if (ans.size() == k && x == n + 1)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    if (ans.size() > k)
        return;
    if (n - x + 1 < k - ans.size())
        return;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i].push_back(x);
        gen(x + 1, ans);
        ans[i].pop_back();
    }
    vector<int> y;
    y.push_back(x);
    ans.push_back(y);
    gen(x + 1, ans);
    ans.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
    cin >> n >> k;
    vector<vector<int> > ans;
    gen(1, ans);
    return 0;
}



