#include <stdio.h>
#include <assert.h>
#include <vector>
#include <random>
#include <algorithm>

struct node {
    int val, mn;
    int prior, sz;
    node *l, *r;
    node(int base) :
        val(base), mn(base),
        prior(rand()), sz(1),
        l(NULL), r(NULL) {};
};
typedef node* trep;

int get_sz(trep &it)
{
    return it ? it->sz : 0;
}

void upd(trep &it)
{
    if (it) {
        it->sz = 1 + get_sz(it->l) + get_sz(it->r);
        it->mn = it->val;
        if (it->l && it->l->mn < it->mn)
            it->mn = it->l->mn;
        if (it->r && it->r->mn < it->mn)
            it->mn = it->r->mn;
    }
}

void split(int cnt, trep it, trep &l, trep &r)
{
    if (!it) {
        l = r = NULL;
        return;
    }
    int it_pos = get_sz(it->l);
    if (it_pos < cnt)
        split(cnt - it_pos - 1, it->r, it->r, r),
        upd(l = it);
    else
        split(cnt, it->l, l, it->l),
        upd(r = it);
}

void merge(trep& it, trep l, trep r)
{
    if (!(l && r))
        it = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), it = l;
    else
        merge(r->l, l, r->l), it = r;
    upd(it);
}

void insert(trep &it, int pos, int val)
{
    trep rt;
    split(pos, it, it, rt);
    merge(it, it, new node(val));
    merge(it, it, rt);
}

int get_min(trep &it, int l, int r) /// [l, r)
{
    trep lt, rt;
    split(r, it, it, rt);
    split(l, it, lt, it);
    int res = it->mn;
    merge(it, lt, it);
    merge(it, it, rt);
    return res;
}

void pr(trep it)
{
    if (!it) return;
    pr(it->l);
    printf("%d ", it->val);
    pr(it->r);
}

int main()
{
    trep root = NULL;
    std::vector<int> v;
    for (int i = 0; i < 200; ++i)
        insert(root, i/2 + i/3, i),
        v.insert(v.begin() + i/2 + i/3, i);

    for (int it : v)
        printf("%d ", it);
    printf("\n");
    pr(root);
    printf("\n");

    for (int i = 0; i < 20; ++i)
        for (int j = i; j < 20; ++j)
            assert(*min_element(v.begin() + i, v.begin() + j + 1) == get_min(root, i, j+1));


    return 0;
}
