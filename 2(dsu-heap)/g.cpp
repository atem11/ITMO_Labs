#include <bits/stdc++.h>

using namespace std;

struct el
{
    int l, r;
    long long val;
};

bool comp(el &a, el &b)
{
    return a.val > b.val;
}

vector<pair<long long, int> > ans;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<el> zp;
    ans.resize(n);
    for (int i = 0; i < n; i++)
        ans[i].second = -1;
    long long mx = 0;
    for (int i = 0; i < m; i++)
    {
        el a;
        cin >> a.l >> a.r >> a.val;
        mx = max(mx, a.val);
        zp.push_back(a);
    }
    mx++;
    sort(zp.begin(), zp.end(), comp);
    for (int i = 0; i < m; i++)
    {
        for (int k = zp[i].l - 1; k < zp[i].r; k++)
        {
            if (ans[k].second == -1)
            {
                //cout << k << ' ' << zp[i].val << '\n' << '\n';
                ans[k].second = zp[i].r;
                ans[k].first = zp[i].val;
            }
            else
            {
                //cout << k << ' ' << zp[i].val << '\n';
                k = ans[k].second - 1;
                //cout << k << ' ' << zp[i].val << '\n' << '\n';
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (ans[i].second == -1) ans[i].first = mx;
    for (int i = 0; i < n; i++)
        cout << ans[i].first << ' ';
    return 0;
}
