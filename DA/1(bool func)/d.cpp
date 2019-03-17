#include <bits/stdc++.h>

using namespace std;

unsigned long long k, ans = 0, n;
unsigned long long znach[5];
vector<string> form;

void gen(int sz, unsigned long long res, string frm, bool use)
{
    if (sz == 0)
    {
        bool f = 1;
        unsigned long long nk = k, nres = res;
        while (nres > 0 || nk > 0)
        {
            if (nk % 2 == 0 && nres % 2 == 1) f = 0;
            nres = nres >> 1;
            nk = nk >> 1;
        }
        if (f)
        {
            form.push_back(frm);
            ans = ans | res;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            unsigned long long nres;
            char num = (char)('0' + i + 1);
            string nfrm;
            nres = res & znach[i];
            if (use) nfrm = frm + num;
            else nfrm = frm + "&" + num;
            gen(sz - 1, nres, nfrm, false);
            nres = res & ~znach[i];
            if (use) nfrm = frm + "~" + num;
            else nfrm = frm + "&~" + num;
            gen(sz - 1, nres, nfrm, false);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> znach[i];
    cin >> k;
    unsigned long long zero = ~0;
    for (int i = 1; i <= n + 1; i++)
        gen(i, zero, "", true);
    if (ans != k)
        cout << "Impossible\n";
    else
    {
        for (int i = 0; i < form.size(); i++)
        {
            if (i != 0)
                cout << '|';
            cout << "(" << form[i] << ")";
        }
    }
    return 0;
}
