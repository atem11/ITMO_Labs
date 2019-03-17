#include <bits/stdc++.h>

using namespace std;

bool use[17];
int n, m;

void gen(int k, string ans, int t)
{
    if (k == 0)
        cout << ans << '\n';
    else
        for (int i = t + 1; i <= n; i++)
        {
            string ch;
            if (i == 1) ch = "1 ";
            if (i == 2) ch = "2 ";
            if (i == 3) ch = "3 ";
            if (i == 4) ch = "4 ";
            if (i == 5) ch = "5 ";
            if (i == 6) ch = "6 ";
            if (i == 7) ch = "7 ";
            if (i == 8) ch = "8 ";
            if (i == 9) ch = "9 ";
            if (i == 10) ch = "10 ";
            if (i == 11) ch = "11 ";
            if (i == 12) ch = "12 ";
            if (i == 13) ch = "13 ";
            if (i == 14) ch = "14 ";
            if (i == 15) ch = "15 ";
            if (i == 16) ch = "16 ";
            if (!use[i])
            {
                use[i] = 1;
                gen(k - 1, ans + ch, i);
                use[i] = 0;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);
    cin >> n >> m;
    gen(m, "", 0);
    return 0;
}



