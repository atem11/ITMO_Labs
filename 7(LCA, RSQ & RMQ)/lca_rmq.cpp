#include <bits/stdc++.h>

using namespace std;

int const MAX = 1e5 + 7;
int n;
int root = 0;
vector<vector<int> > g;
bool used[MAX];
vector<int> d, vtx, Ind;

void dfs(int v, int deep) {
    used[v] = true;
    vtx.push_back(v);
    d[v] = deep;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (!used[u]) {
            dfs(u, deep + 1);
            vtx.push_back(v);
        }
    }
}


vector<int> st, poww;
vector<vector<int> > sparse;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("lca_rmq.in", "r", stdin);
    freopen("lca_rmq.out", "w", stdout);
    int m;
	cin >> n >> m;
	g.resize(n);
	d.resize(n);
	string s;
	int x, y, z;
	int a1, a2;
	for (int i = 1; i < n; i++) {
        cin >> x;
        g[x].push_back(i);
	}
	cin >> a1 >> a2 >> x >> y >> z;
	dfs(root, 0);
	Ind.assign(n, -1);
	for (size_t i = 0; i < vtx.size(); ++i) {
        int v = vtx[i];
        if (Ind[v] == -1) {
            Ind[v] = i;
        }
 	}

 	st.resize(vtx.size() + 1);
    st[1] = 0;
 	int p = 1;
    for (int i = 2; i <= (int)vtx.size(); i++) {
        if (p * 2 > i) {
            st[i] = st[i - 1];
        } else {
            p *= 2;
            st[i] = st[i - 1] + 1;
        }
    }
    p = 1;
    while (p <= (int)vtx.size()) {
        poww.push_back(p);
        p *= 2;
    }
    sparse.resize(st[vtx.size()] + 1);
    for (size_t i = 0; i < vtx.size(); i++) {
        sparse[0].push_back(vtx[i]);
    }
    p = 1;
    for (int i = 1; i <= st[vtx.size()]; i++) {
        for (size_t j = 0; j < vtx.size(); j++) {
            if (j + 2 * p <= vtx.size()) {
                if (d[sparse[i - 1][j]] < d[sparse[i - 1][j + p]]) {
                    sparse[i].push_back(sparse[i - 1][j]);
                } else {
                    sparse[i].push_back(sparse[i - 1][j + p]);
                }
            }
        }
        p *= 2;
    }


 	vector<long long> zap(2 * m);
 	int u = Ind[a1], v = Ind[a2];
 	if (u > v) swap(u, v);
    int l = v - u + 1;
 	int ans;
 	if (d[sparse[st[l]][u]] < d[sparse[st[l]][u + (l - poww[st[l]])]]) {
        ans = sparse[st[l]][u];
 	} else {
 	    ans = sparse[st[l]][u + (l - poww[st[l]])];
 	}
 	long long All_ans = ans;
 	zap[0] = a1;
 	zap[1] = a2;
 	for (int i = 1; i < m; i++) {
        zap[2 * i] = (x * zap[2 * i - 2] + y * zap[2 * i - 1] + z) % n;
        zap[2 * i + 1] = (x * zap[2 * i - 1] + y * zap[2 * i] + z) % n;
 	}
 	for (int i = 1; i < m; i++) {
        a2 = (int)zap[2 * i + 1];
        a1 = (int)((zap[2 * i] + ans) % n);
        u = Ind[a1];
        v = Ind[a2];
        if (u > v) swap(u, v);
        l = v - u + 1;
        if (d[sparse[st[l]][u]] < d[sparse[st[l]][u + (l - poww[st[l]])]]) {
            ans = sparse[st[l]][u];
        } else {
            ans = sparse[st[l]][u + (l - poww[st[l]])];
        }
        All_ans += ans;
 	}
 	cout << All_ans << '\n';
	return 0;
}

