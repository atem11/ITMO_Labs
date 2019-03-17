#include <bits/stdc++.h>

using namespace std;

int const MAX = 5e5 + 7;
int const MAXN = 1e6 + 7;
int n;
int root = 0;
vector<vector<int> > g;
vector<pair<int, int> > zap;
bool used[MAX];
vector<int> d, vtx, Ind;

int uk = -1;
struct el
{
    int l, r;
    int ls, rs;
    int mn, ind;
};

vector<el> tree;

int build(int L, int R)
{
    uk++;
    int v = uk;
    el x;
    tree.push_back(x);
    tree[v].l = L;
    tree[v].r = R;
    if (L == R)
    {
        tree[v].mn = d[L];
        tree[v].ind = L;
    }
    else
    {
        int mid = (L + R) / 2;
        int lu = build(L, mid);
        int ru = build(mid + 1, R);
        tree[v].ls = lu;
        tree[v].rs = ru;
        tree[v].mn = min(tree[lu].mn, tree[ru].mn);
        tree[v].ind = tree[lu].ind;
        if (tree[lu].mn > tree[ru].mn) {
            tree[v].ind = tree[ru].ind;
        }
    }
    return v;
}

pair<int, int> mint(int v, int l, int r)
{
    if (l > r) return {MAXN, 0};
    if (l == tree[v].l && r == tree[v].r)
        return {tree[v].mn, tree[v].ind};
    int vl = tree[v].ls, vr = tree[v].rs;
    int mid = (tree[v].l + tree[v].r) / 2;
    pair<int, int> L = mint(vl, l, min(r, mid)), R = mint(vr, max(l, mid + 1), r);
    if (L.first > R.first) {
        return R;
    }
    return L;
}

void print(int v) {
    if (tree[v].l == tree[v].r) {
        cout << tree[v].l << ' ' << tree[v].r << ' ' << tree[v].mn << ' ' << tree[v].ind << '\n';
    } else {
        print(tree[v].ls);
        cout << tree[v].l << ' ' << tree[v].r << ' ' << tree[v].mn << ' ' << tree[v].ind << '\n';
        print(tree[v].rs);
    }
}

void dfs(int v, int deep) {
    used[v] = true;
    d.push_back(deep);
    vtx.push_back(v);
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (!used[u]) {
            dfs(u, deep + 1);
            vtx.push_back(v);
            d.push_back(deep);
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
	cin >> n;
	g.resize(n);
	string s;
	int x, y;
	int S = 0;
	for (int i = 0; i < n; i++) {
        cin >> s >> x >> y;
        x--;
        y--;
        if (y > S) S = y;
        if (s == "ADD") {
            if (y == root) root = x;
            g[x].push_back(y);
        } else {
            zap.push_back({x, y});
        }
	}
	dfs(root, 0);
	Ind.assign(S + 1, -1);
	for (size_t i = 0; i < vtx.size(); ++i) {
        int v = vtx[i];
        if (Ind[v] == -1) {
            Ind[v] = i;
        }
 	}
 	build(0, d.size() - 1);
 	/*for (int i = 0; i < d.size(); i++) {
        cout << d[i] << ' ';
 	} cout << '\n';
 	for (int i = 0; i < vtx.size(); i++) {
        cout << vtx[i] << ' ';
 	} cout << '\n';
 	for (int i = 0; i < Ind.size(); i++) {
        cout << Ind[i] << ' ';
 	} cout << '\n';
 	print(0);*/

 	for (size_t i = 0; i < zap.size(); ++i) {
        int u = zap[i].first, v = zap[i].second;
        if (Ind[u] > Ind[v]) swap(u, v);
        pair<int, int> Ans = mint(0, Ind[u], Ind[v]);
        //cout << Ans.first << ' ' << Ans.second << '\n';
        cout << vtx[Ans.second] + 1 << '\n';
 	}
	return 0;
}
