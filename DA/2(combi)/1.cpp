#include <bits/stdc++.h>

using namespace std;

void gen(int k, string ans)
{
    if (k == 0)
        cout << ans << '\n';
    else
    {
        gen(k - 1, ans + "0");
        gen(k - 1, ans + "1");
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    int n;
    cin >> n;
    gen(n, "");
    return 0;
}
