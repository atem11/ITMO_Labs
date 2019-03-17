#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > p;
vector<int> rnk;

pair<int,int> find_set(int v)
{
	if (v != p[v].first)
    {
		int clr = p[v].second;
		p[v] = find_set(p[v].first);
		p[v].second ^= clr;
	}
	return p[v];
}

void union_set(int a, int b)
{
	pair<int,int> pa = find_set(a);
	a = pa.first;
	int x = pa.second;
	pair<int,int> pb = find_set(b);
	b = pb.first;
	int y = pb.second;
	if (a != b)
    {
		if (rnk[a] < rnk[b])
			swap(a, b);
		p[b] = {a, x ^ y ^ 1};
		if (rnk[a] == rnk[b])
			rnk[a]++;
	}
}


int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, shift;
    shift = 0;
    cin >> n >> m;
    p.resize(n);
    rnk.resize(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = {i, 0};
        rnk[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> z >> x >> y;
        x = (x + shift) % n;
        if (x == 0) x = n;
        y = (y + shift) % n;
        if (y == 0) y = n;
        x--;
        y--;
        if (z == 0)
            union_set(x, y);
        else
        {
            pair<int, int> pa = find_set(x);
            pa = find_set(y);
            if (p[x].second == p[y].second)
            {
                shift++;
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}
