#include <bits/stdc++.h>

using namespace std;

void gen(int k, int ma, vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
    for (int i = ma; i <= k; i++)
    {
        ans.push_back(i);
        gen(k, i + 1, ans);
        ans.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a;
    gen(n, 1, a);
    return 0;
}


