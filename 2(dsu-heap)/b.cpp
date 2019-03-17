#include <bits/stdc++.h>

using namespace std;

struct el
{
    int p, r;
    int mn;
    int mx;
    int k;
};

el *dsu;

int find_set(int v)
{
    if (v == dsu[v].p)
        return v;
    return dsu[v].p = find_set(dsu[v].p);
}

void union_set (int v1, int v2)
{
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 != v2)
    {
        if (dsu[v1].r < dsu[v2].r)
            swap(v1, v2);
        dsu[v2].p = v1;
        if (dsu[v1].mx < dsu[v2].mx) dsu[v1].mx = dsu[v2].mx;
        if (dsu[v1].mn > dsu[v2].mn) dsu[v1].mn = dsu[v2].mn;
        dsu[v1].k += dsu[v2].k;
        if (dsu[v1].r == dsu[v2].r)
            dsu[v1].r++;
    }
}

void get_set(int v)
{
    v = find_set(v);
    cout << dsu[v].mn << ' ' << dsu[v].mx << ' ' << dsu[v].k << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("dsu.in", "r", stdin);
    freopen("dsu.out", "w", stdout);
    int n;
    cin >> n;
    dsu = new el[n];
    for (int v = 0; v < n; v++)
    {
        dsu[v].p = v;
        dsu[v].r = 0;
        dsu[v].mn = v + 1;
        dsu[v].mx = v + 1;
        dsu[v].k = 1;
    }
    string s;
    while (cin >> s)
    {
        int x, y;
        cin >> x;
        --x;
        if (s == "get") get_set(x);
        else
        {
            cin >> y;
            --y;
            union_set(x, y);
        }
    }
    return 0;
}
