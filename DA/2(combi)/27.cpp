#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    string s;
    cin >> s;
    int bal = 0, f = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            bal--;
        else
            bal++;
        if (s[i] == '(' && bal > 0)
        {
            f = 1;
            int op = (s.size() - i - bal) / 2;
            s[i] = ')';
            for (int j = i + 1; j < s.size(); j++)
                if (op > 0)
                {
                    s[j] = '(';
                    op--;
                }
                else
                    s[j] = ')';
            break;
        }
    }
    if (f)
        cout << s;
    else
        cout << '-';
    return 0;
}
