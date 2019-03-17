#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > answer;

void gen(int k, int ma, vector<int> ans)
{
    if (k == 0)
    {
        answer.push_back(ans);
    }
    else
    {
        for (int i = ma; i <= k; i++)
        {
            ans.push_back(i);
            gen(k - i, i, ans);
            ans.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a;
    gen(n, 1, a);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            if (j == 0) cout << answer[i][j];
            else cout << '+' << answer[i][j];
        }
        cout << '\n';
    }
    return 0;
}

