#include <bits/stdc++.h>

using namespace std;

int n, uk = -1;

struct el
{
    int l, r;
    int ls, rs;
    long long sum;
};

vector<el> tree;
long long *mas;

int build(int L, int R)
{
    uk++;
    int v = uk;
    el x;
    tree.push_back(x);
    tree[v].l = L;
    tree[v].r = R;
    if (L == R)
    {
        tree[v].sum = mas[L];
    }
    else
    {
        int mid = (L + R) / 2;
        int lu = build(L, mid);
        int ru = build(mid + 1, R);
        tree[v].ls = lu;
        tree[v].rs = ru;
        tree[v].sum = tree[lu].sum + tree[ru].sum;
    }
    return v;
}

long long sumt(int v, int l, int r)
{
    if (l > r) return 0;
    if (l == tree[v].l && r == tree[v].r)
        return tree[v].sum;
    int vl = tree[v].ls, vr = tree[v].rs;
    int mid = (tree[v].l + tree[v].r) / 2;
    return sumt(vl, l, min(r, mid)) + sumt(vr, max(l, mid + 1), r);
}

void update(int v, int nv, long long new_val)
{
    if (tree[v].l == tree[v].r)
        tree[v].sum = new_val;
    else
    {
        int mid = (tree[v].l + tree[v].r) / 2;
        if (nv <= mid)
            update(tree[v].ls, nv, new_val);
        else
            update(tree[v].rs, nv, new_val);
        tree[v].sum = tree[tree[v].ls].sum + tree[tree[v].rs].sum;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("rsq.in", "r", stdin);
    freopen("rsq.out", "w", stdout);
    cin >> n;
    mas = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    long long y, x = (long long)build(0, n - 1);
    string s;
    while (cin >> s >> x >> y)
    {
        if (s == "sum")
        {
            x--;
            y--;
            cout << sumt(0, (int)x, (int)y) << '\n';
        }
        if (s == "set")
        {
            x--;
            update(0, (int)x, y);
        }
    }
    return 0;
}

