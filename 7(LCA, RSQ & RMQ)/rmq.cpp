#include <bits/stdc++.h>

using namespace std;

int n, uk = -1;

struct el
{
    int l, r;
    int ls, rs;
    int mn;
};

vector<el> tree;
int *mas;

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
        tree[v].mn = mas[L];
    }
    else
    {
        int mid = (L + R) / 2;
        int lu = build(L, mid);
        int ru = build(mid + 1, R);
        tree[v].ls = lu;
        tree[v].rs = ru;
        tree[v].mn = min(tree[lu].mn, tree[ru].mn);
    }
    return v;
}

int mint(int v, int l, int r)
{
    if (l > r) return 1e9 + 7;
    if (l == tree[v].l && r == tree[v].r)
        return tree[v].mn;
    int vl = tree[v].ls, vr = tree[v].rs;
    int mid = (tree[v].l + tree[v].r) / 2;
    return min(mint(vl, l, min(r, mid)), mint(vr, max(l, mid + 1), r));
}

void update(int v, int nv, int new_val)
{
    if (tree[v].l == tree[v].r)
        tree[v].mn = new_val;
    else
    {
        int mid = (tree[v].l + tree[v].r) / 2;
        if (nv <= mid)
            update(tree[v].ls, nv, new_val);
        else
            update(tree[v].rs, nv, new_val);
        tree[v].mn = min(tree[tree[v].ls].mn, tree[tree[v].rs].mn);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    cin >> n;
    mas = new int[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    int y, x = build(0, n - 1);
    string s;
    while (cin >> s >> x >> y)
    {
        if (s == "min")
        {
            x--;
            y--;
            cout << mint(0, x, y) << '\n';
        }
        if (s == "set")
        {
            x--;
            update(0, x, y);
        }
    }
    return 0;
}
