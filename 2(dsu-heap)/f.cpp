#include <bits/stdc++.h>

using namespace std;

struct el
{
    int p, rnk;
};

struct mn
{
    int zap, v, u;
};

el *dsu;
mn *z;

int find_set(int v)
{
    if (v == dsu[v].p)
        return v;
    else return dsu[v].p = find_set(dsu[v].p);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (dsu[a].rnk < dsu[b].rnk)
            swap(a, b);
        dsu[b].p = a;
        if (dsu[a].rnk == dsu[b].rnk) dsu[a].rnk++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("cutting.in", "r", stdin);
    freopen("cutting.out", "w", stdout);
    int n, m, k;
    vector<string> ans;
    cin >> n >> m >> k;
    z = new mn[k];
    dsu = new el[n];
    for (int i = 0 ; i < n; i ++)
        dsu[i].p = i, dsu[i].rnk =0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
    }
    for (int i = 0; i < k; i++)
    {
        string s;
        int x, y;
        cin >> s >> x >> y;
        x--;
        y--;
        z[i].v = x;
        z[i].u = y;
        if (s == "ask") z[i].zap = 0;
        else z[i].zap = 1;
    }
    for (int i = k - 1; i >= 0; i--)
    {
        if (z[i].zap)
        {
            union_set(z[i].v, z[i].u);
        }
        else
        {
            if (find_set(z[i].v) == find_set(z[i].u)) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }
    for (int i = int(ans.size() - 1); i >= 0; i--)
        cout << ans[i] << '\n';
    return 0;
}
