#include <bits/stdc++.h>

using namespace std;

void gen(int k)
{
    int kol = 1 << k;
    for (int i = 0; i < kol; i++)
    {
        int ans = i ^ (i / 2);
        string s = "";
        for (int j = 0; j < k; j++)
        {
            if (ans % 2 == 0) s = "0" + s;
            else s = "1" + s;
            ans /= 2;
        }
        cout << s << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("gray.in", "r", stdin);
    freopen("gray.out", "w", stdout);
    int n;
    cin >> n;
    gen(n);
    return 0;
}

