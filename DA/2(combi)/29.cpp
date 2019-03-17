#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nextpartition.in", "r", stdin);
    freopen("nextpartition.out", "w", stdout);
    int n, answ;
    cin >> answ;
    vector <int> ans;
    char ch;
    while (cin >> ch)
    {
        int x;
        cin >> x;
        ans.push_back(x);
    }
    n = ans.size();
    if (n == 1)
    {
        cout << "No solution";
        return 0;
    }
    n--;
    ans[n - 1]++;
    ans[n]--;
    if (ans[n] < ans[n - 1])
    {
        ans[n - 1] += ans[n];
        ans.pop_back();
    }
    else
    {
        int uk = ans[n - 1];
        while (ans[n] >= 2 * uk)
        {
            ans.push_back(ans[n] - uk);
            ans[n] = uk;
            n++;
        }

    }
    cout << answ << '=' << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << '+' << ans[i];
    return 0;
}
