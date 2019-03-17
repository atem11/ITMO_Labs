#include <bits/stdc++.h>

using namespace std;

void gen(int k, string ans, int bal)
{
    if (k == 0)
        cout << ans << '\n';
    else
    {
        if (bal == 0) gen(k - 1, ans + "(", bal + 1);
        else if (bal == k) gen(k - 1, ans + ")", bal - 1);
            else
            {
                gen(k - 1, ans + "(", bal + 1);
                gen(k - 1, ans + ")", bal - 1);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    int n;
    cin >> n;
    gen(2 * n, "", 0);
    return 0;
}
