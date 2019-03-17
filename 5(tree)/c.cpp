#include <bits/stdc++.h>

using namespace std;

struct node
{
    int y;
    int val;
    int sz;
    node *l, *r;
    node(int value)
    {
        y = rand();
        val = value;
        sz = 1;
        l = r = NULL;
    }
    node(){};
};

node* root = NULL;

int get(node* t)
{
    if (t == NULL)
    {
        return 0;
    }
    return t->sz;
}

void upd(node* t)
{
    if (t == NULL) return;
    t->sz = get(t->l) + get(t->r) + 1;
}

pair<node*, node*> split(node* t, int s)
{
    if (t == NULL)
    {
        return {NULL, NULL};
    }
    if (get(t->l) < s)
    {
        pair<node*, node*> x;
        x = split(t->r, s - get(t->l) - 1);
        t->r = x.first;
        upd(t);
        return {t, x.second};
    }
    else
    {
        pair<node*, node*> x;
        x = split(t->l, s);
        t->l = x.second;
        upd(t);
        return {x.first, t};
    }
}

node* merg(node* l, node* r)
{
    if (l == NULL) return r;
    if (r == NULL) return l;
    if (l->y > r->y)
    {
        l->r = merg(l->r, r);
        upd(l);
        return l;
    }
    else
    {
        r->l = merg(l, r->l);
        upd(r);
        return r;
    }
}

void ins(int val, int sz)
{
    pair<node*, node*> x = split(root, sz);
    root = merg(x.first, new node(val));
    root = merg(root, x.second);
}

void print(node* t)
{
    if (t == NULL) return;
    print(t->l);
    cout << t->val << ' ';
    print(t->r);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ins(i, i);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        pair<node*, node*> ft = split(root, l - 1);
        pair<node*, node*> st = split(ft.second, r - l + 1);
        root = merg(st.first, ft.first);
        root = merg(root, st.second);
    }
    print(root);
    cout << '\n';
    return 0;
}
