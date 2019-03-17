#include <bits/stdc++.h>

using namespace std;

struct el
{
    int p, r;
};

el *dsu;

int find_set(int v)
{
    if (v == dsu[v].p)
        return v;
    return dsu[v].p = find_set(dsu[v].p);
}

void union_set (int v1, int v2)
{
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 != v2)
    {
        if (dsu[v1].r < dsu[v2].r)
            swap(v1, v2);
        dsu[v2].p = v1;
        if (dsu[v1].r == dsu[v2].r)
            dsu[v1].r++;
    }
}

struct edge{
    int w, u, v;
};

vector<edge> ed;

long long ans = 0;

bool cmp(edge &a, edge &b) {
    return a.w < b.w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    dsu = new el[n];
    ed.resize(m);
    int u, v, w;
    for (int i = 0; i < n; ++i) {
        dsu[i].p = i;
        dsu[i].r = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        ed[i].u = u - 1;
        ed[i].v = v - 1;
        ed[i].w = w;
    }
    sort(ed.begin(), ed.end(), cmp);
    for (size_t i = 0; i < ed.size(); ++i) {
        u = ed[i].u;
        v = ed[i].v;
        if (find_set(u) != find_set(v)) {
            ans += (long long)ed[i].w;
            union_set(u, v);
        }
    }
    cout << ans << '\n';
    return 0;
}

