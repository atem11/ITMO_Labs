#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<int> > automat, Tautomat, newautomat;
vector<int> exit1, answ;
bool ext[100000], use[100000], used[100000], cycle = false;
int ans[100000];
int mod = 1e9+7;
queue<int> q;
int clr[100000];

void dfs(int v) {
    use[v] = true;
    for (int i = 0; i < Tautomat[v].size(); i++) {
        int to = Tautomat[v][i];
        newautomat[to].push_back(v);
        if (!use[to]) dfs(to);
    }
}

void dfs1(int v) {
	used[v] = true;
	for (size_t i = 0; i < newautomat[v].size(); ++i) {
		int to = newautomat[v][i];
		if (!used[to])
			dfs1 (to);
	}
	answ.push_back(v);
}

void dfs2(int v) {
    clr[v] = 1;
    for (int i = 0; i < newautomat[v].size(); i++) {
        int to = newautomat[v][i];
        if (clr[to] == 1) {
            cycle = true;
        }
        if (clr[to] == 0) {
            dfs2(to);
        }
    }
    clr[v] = 2;
}

void topological_sort() {
    dfs1(0);
	reverse(answ.begin(), answ.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        ext[x - 1] = true;
        exit1.push_back(x - 1);
    }
    automat.resize(n);
    newautomat.resize(n);
    Tautomat.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--;
        b--;
        automat[a].push_back(b);
        Tautomat[b].push_back(a);
    }
    for (int i = 0; i < exit1.size(); i++) {
        if (clr[exit1[i]] == 0) dfs(exit1[i]);
    }
    dfs2(0);
    if (cycle) {
        cout << -1 << '\n';
        return 0;
    }
    topological_sort();
    ans[0] = 1;
    for (int k = 0; k < answ.size(); k++) {
        int v = answ[k];
        for (int i = 0; i < automat[v].size(); i++) {
            ans[automat[v][i]] += ans[v] % mod;
            ans[automat[v][i]] %= mod;
        }
    }
    int anss = 0;
    for (int i = 0; i < exit1.size(); i++) {
        anss += ans[exit1[i]] % mod;
        anss %= mod;
    }
    cout << anss << '\n';
    return 0;
}
