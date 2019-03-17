#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > g;
vector<bool> use;

bool dfs(int v, int a)
{
    bool f = false;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (f) break;
        if (g[v][i] == a)
        {
            f = true;
            break;
        }
        else
        {
            if (!use[g[v][i]])
            {
                use[g[v][i]] = 1;
                f = dfs(g[v][i], a);
            }
        }
    }
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    g.resize(2 * n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        bool f1 = 0, f2 = 0;
        if (x > 0) f1 = 1;
        if (y > 0) f2 = 1;
        x = abs(x);
        y = abs(y);
        x--;
        y--;
        if (!f1) x += n;
        if (!f2) y += n;
        if (x >= n)
        {
            g[x - n].push_back(y);
            //cout << x - n << ' ' << y << '\n';
        }
        else
        {
            g[x + n].push_back(y);
            //cout << x + n << ' ' << y << '\n';
        }
        if (y >= n)
        {
            g[y - n].push_back(x);
            //cout << y - n << ' ' << x << '\n';
        }
        else
        {
            g[y + n].push_back(x);
            //cout << y + n << ' ' << x << '\n';
        }
    }
    use.resize(2 * n);
    bool f = false;
    bool f1 = false;
    for (int i = 0; i < n; i++)
    {
        f = false;
        f1 = false;
        for (int j = 0; j < 2 * n; j++) use[j] = 0;
        f = dfs(i, i + n);
        for (int j = 0; j < 2 * n; j++) use[j] = 0;
        f1 = dfs(i + n, i);
        if (f && f1) break;
    }
    if (f && f1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
