#include <bits/stdc++.h>

using namespace std;

const int Inf = 1e9 + 7;

struct node
{
    int y;
    int x;
    node *l, *r;
    node(int x1)
    {
        y = rand();
        x = x1;
        l = r = NULL;
    }
    node(){};
};

node* root = NULL;

pair<node*, node*> split(node* t, int x)
{
    if (t == NULL)
    {
        return {NULL, NULL};
    }
    if (t->x < x)
    {
        pair<node*, node*> nt = split(t->r, x);
        t->r = nt.first;
        return {t, nt.second};
    }
    else
    {
        pair<node*, node*> nt = split(t->l, x);
        t->l = nt.second;
        return {nt.first, t};
    }
}

node* merg(node* l, node* r)
{
    if (l == NULL)
        return r;
    if (r == NULL)
        return l;
    if (l->y > r->y)
    {
        l->r = merg(l->r, r);
        return l;
    }
    else
    {
        r->l = merg(l, r->l);
        return r;
    }
}

void print(node* t)
{
    if (t != NULL)
    {
        print(t->l);
        cout << t->x << ' ';
        print(t->r);
    }
}

void ins(int x)
{
    pair<node*, node*> nt = split(root, x);
    root = merg(nt.first, new node(x));
    root = merg(root, nt.second);

}

void del(node* t, int x)
{
    pair<node*, node*> a, b;
    a = split(t, x);
    b = split(a.second, x + 1);
    root = merg(a.first, b.second);
}

bool exists(node* t, int x)
{
    bool f = 0;
    if (t == NULL)
        return f;
    if (t->x == x)
        return 1;
    else
        if (t->x > x)
            f = exists(t->l, x);
        else
            f = exists(t->r, x);
    return f;
}

int next(node* t, int x)
{
    int ans;
    pair<node*, node*> nt = split(t, x + 1);
    if (nt.second == NULL)
        ans = Inf;
    else
    {
        t = nt.second;
        while (t != NULL)
        {
            ans = t->x;
            t = t->l;
        }
    }
    root = merg(nt.first, nt.second);
    return ans;
}

int prev(node* t, int x)
{
    int ans;
    pair<node*, node*> nt = split(t, x);
    if (nt.first == NULL)
        ans = Inf;
    else
    {
        t = nt.first;
        while (t != NULL)
        {
            ans = t->x;
            t = t->r;
        }
    }
    root = merg(nt.first, nt.second);
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    int x;
    while (cin >> s)
    {
        cin >> x;
        if (s == "insert")
        {
            ins(x);
        }
        if (s == "delete")
        {
            del(root, x);
        }
        if (s == "exists")
        {
            if (exists(root, x)) cout << "true" << '\n';
            else cout << "false" << '\n';
        }
        if (s == "next")
        {
            int z = next(root, x);
            if (z == Inf) cout << "none\n";
            else cout << z << '\n';
        }
        if (s == "prev")
        {
            int z = prev(root, x);
            if (z == Inf) cout << "none\n";
            else cout << z << '\n';
        }
        if (s == "p")
        {
            print(root);
            cout << '\n';
        }
        if (s == "s")
        {
            pair<node*, node*> nt = split(root, x);
            print(nt.first);
            cout << '\n';
            print(nt.second);
            cout << '\n';
            root = merg(nt.first, nt.second);
        }
    }
    return 0;
}

