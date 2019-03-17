#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > parent;
vector<int> kol;
vector<int> rnk;
long long zerg = 0, p = 1e6 + 3;


int find_set(int v)
{
	while (v != parent[v].first)
    {
        v = parent[v].first;
    }
	return v;
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b].first = a;
        parent[b].second -= parent[a].second;
        if (rnk[a] == rnk[b])
            rnk[a]++;
        zerg = ((long long)13 * zerg + (long long)11) % p;
	}
}

void inc_set(int v)
{
    v = find_set(v);
    parent[v].second++;
}

int kol_message(int v)
{
    int ans;
    int v1 = v;
    int k = 0;
    while (v != parent[v].first)
    {
        k += parent[v].second;
        v = parent[v].first;
    }
    k += parent[v].second;
    ans = k;
    ans -= kol[v1];
    kol[v1] = k;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    parent.resize(n);
    rnk.reserve(n);
    kol.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = {i, 0};
        kol[i] = 0;
        rnk[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            x = (x + (int)zerg) % n;
            inc_set(x);
            zerg = ((long long)30 * zerg + (long long)239) % p;
        }
        if (t == 2)
        {
            int x, y;
            cin >> x >> y;
            x = (x + (int)zerg) % n;
            y = (y + (int)zerg) % n;
            union_set(x, y);
        }
        if (t == 3)
        {
            int x;
            cin >> x;
            x = (x + (int)zerg) % n;
            int q = kol_message(x);
            zerg = ((long long)100500 * zerg + (long long)q) % p;
            cout << q << '\n';
        }
    }
    return 0;
}

