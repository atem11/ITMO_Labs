#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    int valtr;
    int updt;
    int cnt;
    int y;
    node *l;
    node *r;
    node(int value)
    {
        val = value;
        valtr = value;
        updt = 0;
        cnt = 1;
        y = rand();
        l = r = NULL;
    }
    node(){};
};

static int getcnt(node* v)
{
    if (v == NULL)
        return 0;
    return v->cnt;
}

static int getvaltr(node* v)
{
    if (v == NULL)
        return -1e9 - 7;
    return v->valtr;
}

void update(node *v)
{
    if (v == NULL)
        return;
    v->valtr = max(max(getvaltr(v->l), v->val), getvaltr(v->r));
    v->cnt = 1 + getcnt(v->l) + getcnt(v->r);
}

void pushupdt(node* v)
{
    if (v == NULL)
        return;
    if (v->l)
    {
        v->l->updt = v->l->updt + v->updt;
        v->l->val = v->l->val + v->updt;
        v->l->valtr = v->l->valtr + v->updt;
    }
    if (v->r)
    {
        v->r->updt = v->r->updt + v->updt;
        v->r->val = v->r->val + v->updt;
        v->r->valtr = v->r->valtr + v->updt;
    }
    v->updt = 0;
}

void merg(node* &t, node* l, node* r)
{
    pushupdt(l);
    pushupdt(r);
    if (l == NULL)
        t = r;
    else
        if (r == NULL)
            t = l;
        else
            if (l->y < r->y)
                merg(l->r, l->r, r), t = l;
            else
                merg(r->l, l, r->l), t = r;
    update(t);
}

void split(node* t, node* &l, node* &r, int key)
{
    pushupdt(t);
    if (t == NULL)
        l = r = NULL;
    else
        if (key <= getcnt(t->l))
            split(t->l, l, t->l, key), r = t;
        else
            split(t->r, t->r, r, key - getcnt(t->l) - 1), l = t;
    update(t);
}

int get(node* t, int ind)
{
    pushupdt(t);
    if (ind < getcnt(t->l))
        return get(t->l, ind);
    else
        if (ind > getcnt(t->l))
            return get(t->r, ind - getcnt(t->l) - 1);
    return t->val;
}

void ins(node* &t, node* item, int ind)
{
    pushupdt(t);
    if (!t)
        t = item;
    else
        if (item->y < t->y)
            split(t, item->l, item->r, ind), t = item;
        else
            if (ind <= getcnt(t->l))
                ins(t->l, item, ind);
            else
                ins(t->r, item, ind - getcnt(t->l) - 1);
    update(t);
}

void rem(node* &t, int ind)
{
    pushupdt(t);
    if (ind == getcnt(t->l))
        merg(t, t->l, t->r);
    else
        if (ind < getcnt(t->l))
            rem(t->l, ind);
        else
            rem(t->r, ind - getcnt(t->l) - 1);
    update(t);
}

long long arr[200000];

int main()
{
    freopen("river.in", "r", stdin);
    freopen("river.out", "w", stdout);
    int n, m, x1;
    cin >> n >> x1;
    node* root = NULL;
    long long ans = 0, sz;
    for (int i = 0; i < n; i++)
    {
        cin >> sz;
        ans += sz * sz;
        arr[i] = sz;
        node *item = new node(i);
        ins(root, item, i);
    }
    cin >> m;
    cout << ans << '\n';
    int cnt = n;
    for (int i = 0; i < m; i++)
    {
        int e, v, l, r;
        cin >> e >> v;
        v--;
        int ind = get(root, v);
        long long x = arr[ind];
        ans -= x * x;
        if (e == 1)
        {
            rem(root, v);
            if (v == 0)
            {
                r = get(root, 0);
                ans -= arr[r] * arr[r];
                arr[r] += x;
                ans += arr[r] * arr[r];
            }
            else
            {
                if (v == getcnt(root))
                {
                    l = get(root, v - 1);
                    ans -= arr[l] * arr[l];
                    arr[l] += x;
                    ans += arr[l] * arr[l];
                }
                else
                {
                    r = get(root, v);
                    ans -= arr[r] * arr[r];
                    arr[r] += x / 2 + x % 2;
                    ans += arr[r] * arr[r];
                    l = get(root, v - 1);
                    ans -= arr[l] * arr[l];
                    arr[l] += x / 2;
                    ans += arr[l] * arr[l];
                }
            }
        }
        else
        {
            arr[ind] = (x / 2);
            arr[cnt++] = (x / 2 + x % 2);
            ans += (x / 2 + x % 2) * (x / 2 + x % 2);
            ans += (x / 2) * (x / 2);
            node *item = new node(cnt - 1);
            ins(root, item, v + 1);
        }
        cout << ans << '\n';
    }
}
