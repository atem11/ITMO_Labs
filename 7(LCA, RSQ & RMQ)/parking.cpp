#include <bits/stdc++.h>

using namespace std;

int n, m, uk = -1;

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
        tree[v].mn = L;
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
    if (l > r) return 1e7;
    if (l == tree[v].l && r == tree[v].r)
        return tree[v].mn;
    int vl = tree[v].ls, vr = tree[v].rs;
    int mid = (tree[v].l + tree[v].r) / 2;
    return min(mint(vl, l, min(r, mid)), mint(vr, max(l, mid + 1), r));
}

void update(int v, int nv)
{
    if (tree[v].l == tree[v].r)
        tree[v].mn = 1e7;
    else
    {
        int mid = (tree[v].l + tree[v].r) / 2;
        if (nv <= mid)
            update(tree[v].ls, nv);
        else
            update(tree[v].rs, nv);
        tree[v].mn = min(tree[tree[v].ls].mn, tree[tree[v].rs].mn);
    }
}

void ext(int v, int nv)
{
    if (tree[v].l == tree[v].r)
        tree[v].mn = tree[v].l;
    else
    {
        int mid = (tree[v].l + tree[v].r) / 2;
        if (nv <= mid)
            ext(tree[v].ls, nv);
        else
            ext(tree[v].rs, nv);
        tree[v].mn = min(tree[tree[v].ls].mn, tree[tree[v].rs].mn);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);
    cin >> n >> m;
    int x = build(0, n - 1);
    string s;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> x;
        if (s == "enter")
        {
            x--;
            int uk = mint(0, x, n - 1);
            if (uk == 1e7) uk = mint(0, 0, x - 1);
            cout << uk + 1 << '\n';
            update(0, uk);
        }
        if (s == "exit")
        {
            x--;
            ext(0, x);
        }
    }
    return 0;
}

