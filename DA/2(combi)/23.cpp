#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
    string s, s1, s2;
    cin >> s;
    s1 = s;
    s2 = s;
    int uk = s1.size() - 1;
    while (s1[uk] != '1')
    {
        uk--;
        if (uk < 0)
            break;
    }
    if (uk < 0)
        cout << "-" << '\n';
    else
    {
        s1[uk] = '0';
        uk++;
        for (int i = uk; i < s1.size(); i++)
            s1[i] = '1';
        cout << s1 << '\n';
    }
    uk = s2.size() - 1;
    while (s2[uk] != '0')
    {
        uk--;
        if (uk < 0)
            break;
    }
    if (uk < 0)
        cout << '-';
    else
    {
        s2[uk] = '1';
        uk++;
        for (int i = uk; i < s2.size(); i++)
            s2[i] = '0';
        cout << s2;
    }
    return 0;
}
