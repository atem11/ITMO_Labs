#include <bits/stdc++.h>

using namespace std;

vector<string> answer;

void gen(int k, string ans, bool t)
{
    if (k == 0)
    {
        answer.push_back(ans);
    }
    else
    {
        gen(k - 1, ans + "0", 0);
        if (t == 0) gen(k - 1, ans + "1", 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    int n;
    cin >> n;
    gen(n, "", 0);
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';
    return 0;
}

