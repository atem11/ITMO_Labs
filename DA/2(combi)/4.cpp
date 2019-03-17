#include <bits/stdc++.h>

using namespace std;

const int K = 1 << 15;

bool use[K];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("chaincode.in", "r", stdin);
    freopen("chaincode.out", "w", stdout);
    int n;
    cin >> n;
    int kol = 1 << n;
    int ans = 0;
    for (int i = 0; i < kol; i++)
    {
        use[ans] = 1;
        string s = "";
        int tr = ans;
        for(int j = 0; j < n; j++)
        {
            if (tr % 2 == 0) s = "0" + s;
            else s = "1" + s;
            tr /= 2;
        }
        cout << s << '\n';
        ans = ans << 1;
        ans %= kol;
        if (!use[ans + 1]) ans += 1;
    }
    return 0;
}

