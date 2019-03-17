#include <bits/stdc++.h>

using namespace std;

struct el
{
    int p, rnk;
    int r;
};

struct el1
{
    int p, rnk;
};

el *dsu;
el1 *dsu1;

int find_set(int v)
{
    if (v == dsu[v].p)
        return v;
    else return dsu[v].p = find_set(dsu[v].p);
}


int find_set1(int v)
{
    if (v == dsu1[v].p)
        return v;
    else return dsu1[v].p = find_set1(dsu1[v].p);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    int R = dsu[b].r;
    if (a != b)
    {
        if (dsu[a].rnk < dsu[b].rnk)
            swap(a, b);
        dsu[b].p = a;
        dsu[a].r = R;
        if (dsu[a].rnk == dsu[b].rnk) dsu[a].rnk++;
    }
}

void union_set1(int a, int b)
{
    a = find_set1(a);
    b = find_set1(b);
    if (a != b)
    {
        if (dsu1[a].rnk < dsu1[b].rnk)
            swap(a, b);
        dsu1[b].p = a;
        if (dsu1[a].rnk == dsu1[b].rnk) dsu1[a].rnk++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("restructure.in", "r", stdin);
    freopen("restructure.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    dsu = new el[n];
    dsu1 = new el1[n];
    for (int i = 0; i < n; i++)
    {
        dsu1[i].p = i;
        dsu[i].p = i;
        dsu1[i].rnk = 0;
        dsu[i].rnk = 0;
        dsu[i].r = i;
    }
    for (int i = 0; i < q; i++)
    {
        int x, y, z;
        cin >> z >> x >> y;
        if (x > y) swap(x, y);
        x--;
        y--;
        if (z == 1)
        {
            int p1, p2;
            p1 = find_set(x);
            p2 = find_set(y);
            union_set1(p1, p2);
            if (x + 1 == y) union_set(x, y);
        }
        if (z == 2)
        {
            for (int k = x; k < y; k++)
            {
                int p = find_set(k);
                int r = dsu[p].r;
                r++;
                if (r <= y)
                {
                    int p1 = find_set(r);
                    union_set1(p, p1);
                    union_set(p, p1);
                    k = r - 1;
                }
                else
                    break;
            }
        }
        if (z == 3)
        {
            int p1, p2;
            p1 = find_set(x);
            p2 = find_set(y);
            p1 = find_set1(p1);
            p2 = find_set1(p2);
            if (p1 == p2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
   /* for (int i = 0; i < n; i++)
    {
        cout << find_set(i) << ' ' << find_set1(i) << '\n';
    }*/
    return 0;
}
