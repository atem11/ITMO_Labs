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

pair<node*, node*> split1(node* t, int val)
{
    if (t == NULL)
    {
        return {NULL, NULL};
    }
    if (t->val < val)
    {
        pair<node*, node*> nt = split1(t->r, val);
        t->r = nt.first;
        upd(t);
        return {t, nt.second};
    }
    else
    {
        pair<node*, node*> nt = split1(t->l, val);
        t->l = nt.second;
        upd(t);
        return {nt.first, t};
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

void ins(int val)
{
    pair<node*, node*> x = split1(root, val);
    root = merg(x.first, new node(val));
    root = merg(root, x.second);
}

void del(int val)
{
    pair<node*, node*> x1 = split1(root, val);
    pair<node*, node*> x2 = split1(x1.second, val + 1);
    root = merg(x1.first, x2.second);
}

int find(int k)
{
    int size = get(root);
    pair<node*, node*> ft = split(root, size - k);
    pair<node*, node*> st = split(ft.second, 1);
    int res = st.first->val;
    root = merg(ft.first, merg(st.first, st.second));
    return res;
}

void print(node* t)
{
    if (t == NULL) return;
    print(t->l);
    cout << t->val << ' ' << t->sz << '\n';
    print(t->r);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            ins(y);
        }
        if (x == -1)
        {
            del(y);
        }
        if (x == 0)
        {
            cout << find(y) << '\n';
        }
    }
    return 0;
}

