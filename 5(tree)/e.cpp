#include <bits/stdc++.h>

using namespace std;

int ans[3000001][3];

struct node
{
    int y;
    int val;
    int ind;
    node *l, *r;
    node(int value, int ind1, int y1)
    {
        y = y1;
        val = value;
        ind = ind1;
        l = r = NULL;
    }
    node(){};
};

node* root = NULL;


pair<node*, node*> split(node* t, int val)
{
    if (t == NULL)
    {
        return {NULL, NULL};
    }
    if (t->val < val)
    {
        pair<node*, node*> nt = split(t->r, val);
        t->r = nt.first;
        return {t, nt.second};
    }
    else
    {
        pair<node*, node*> nt = split(t->l, val);
        t->l = nt.second;
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
        ans[l->ind][2] = l->r->ind;
        if (l->l != NULL)
        {
            ans[l->ind][1] = l->l->ind;
            ans[l->l->ind][0] = l->ind;
        }
        ans[l->r->ind][0] = l->ind;
        return l;
    }
    else
    {
        r->l = merg(l, r->l);
        ans[r->ind][1] = r->l->ind;
        if (r->r != NULL)
        {
            ans[r->ind][2] = r->r->ind;
            ans[r->r->ind][0] = r->ind;
        }
        ans[r->l->ind][0] = r->ind;
        return r;
    }
}

void ins(int val, int y, int ind)
{
    pair<node*, node*> x = split(root, val);
    root = merg(x.first, new node(val, ind, y));
    root = merg(root, x.second);
}

void print(node* t)
{
    if (t == NULL) return;
    print(t->l);
    print(t->r);
    if (t -> r != NULL) {
        ans[t->r->ind][0] = t->ind;
        ans[t->ind][2] = t->r->ind;
    }
    if (t -> l != NULL) {
        ans[t->l->ind][0] = t->ind;
        ans[t->ind][1] = t->l->ind;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ins(x, y, i + 1);
    }
    printf("YES\n");
    //print(root);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
    return 0;
}
