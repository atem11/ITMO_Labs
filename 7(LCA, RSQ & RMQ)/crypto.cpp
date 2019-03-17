#include <bits/stdc++.h>

using namespace std;

int n, r, m, uk = -1;

struct matrx
{
    int a1, a2;
    int a3, a4;
};

matrx E;

matrx multiplay(matrx a, matrx b)
{
    matrx ans;
    ans.a1 = (a.a1 * b.a1 + a.a2 * b.a3) % r;
    ans.a2 = (a.a1 * b.a2 + a.a2 * b.a4) % r;
    ans.a3 = (a.a3 * b.a1 + a.a4 * b.a3) % r;
    ans.a4 = (a.a3 * b.a2 + a.a4 * b.a4) % r;
    return ans;
}

struct el
{
    int l, r;
    int ls, rs;
    matrx mult;
};

vector<el> tree;
matrx *mas;

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
        tree[v].mult = mas[L];
    }
    else
    {
        int mid = (L + R) / 2;
        int lu = build(L, mid);
        int ru = build(mid + 1, R);
        tree[v].ls = lu;
        tree[v].rs = ru;
        tree[v].mult = multiplay(tree[lu].mult, tree[ru].mult);
    }
    return v;
}

matrx mult(int v, int l, int r)
{
    if (l > r) return E;
    if (l == tree[v].l && r == tree[v].r)
        return tree[v].mult;
    int vl = tree[v].ls, vr = tree[v].rs;
    int mid = (tree[v].l + tree[v].r) / 2;
    return multiplay(mult(vl, l, min(r, mid)), mult(vr, max(l, mid + 1), r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);
    E.a1 = 1;
    E.a2 = 0;
    E.a3 = 0;
    E.a4 = 1;
    cin >> r >> n >> m;
    mas = new matrx[n];
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i].a1 >> mas[i].a2 >> mas[i].a3 >> mas[i].a4;
    }
    int y, x = build(0, n - 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        matrx ans = mult(0, x, y);
        cout << ans.a1 << ' ' << ans.a2 << '\n';
        cout << ans.a3 << ' ' << ans.a4 << '\n';
        cout << '\n';
    }
    return 0;
}


