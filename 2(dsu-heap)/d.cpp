#include <bits/stdc++.h>

using namespace std;

struct el
{
    int p, rnk;
    int l, r;
};

el *dsu;

int find_set(int v)
{
    if (v == dsu[v].p)
        return v;
    else return dsu[v].p = find_set(dsu[v].p);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    int R = dsu[b].r;
    int L = dsu[a].l;
    if (a != b)
    {
        if (dsu[a].rnk < dsu[b].rnk)
            swap(a, b);
        dsu[b].p = a;
        dsu[b].l = L;
        dsu[a].r = R;
        if (dsu[a].rnk == dsu[b].rnk) dsu[a].rnk++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);
    int n;
    cin >> n;
    dsu = new el[n];
    for (int i = 0; i < n; i++)
    {
        dsu[i].p = i;
        dsu[i].rnk = 0;
        dsu[i].l = i;
        dsu[i].r = i;
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x;
        x--;
        y = x;
        x = find_set(x);
        cout << dsu[x].r + 1 << ' ';
        union_set(y, (dsu[x].r + 1) % n);
        //for (int k = 0; k < n; k++)
          //  cout << dsu[k].l << '-' << dsu[k].r << ' ';
        //cout << '\n';
    }
    return 0;
}
