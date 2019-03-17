#include <bits/stdc++.h>

using namespace std;

void dfsL(int);

void dfsR(int);

int n, m;
vector<vector<int> > L, R;
bool usedL[4000], usedR[4000], use[4000];

void dfsL(int v) {
    usedL[v] = true;
    for (size_t i = 0; i < L[v].size(); ++i) {
        if (!usedR[L[v][i]]) dfsR(L[v][i]);
    }
}

void dfsR(int v) {
    usedR[v] = true;
    for (size_t i = 0; i < R[v].size(); ++i) {
        if (!usedL[R[v][i]]) dfsL(R[v][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("vertexcover.in", "r", stdin);
    freopen("vertexcover.out", "w", stdout);//*/
    cin >> m >> n;
    L.resize(m);
    R.resize(n);
    vector<vector<int> > ed(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int u;
            cin >> u;
            ed[i].push_back(u - 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        int u;
        cin >> u;
        if (u != 0) {
            R[u - 1].push_back(i);
            use[i] = true;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (size_t j = 0; j < ed[i].size(); ++j) {
            int u = ed[i][j];
            if (R[u].size() == 0 || R[u][0] != i) {
                L[i].push_back(u);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (!use[i] && !usedL[i]) {
            dfsL(i);
        }
    }
    vector<int> ansL, ansR;
    for (int i = 0; i < m; ++i) {
        if (!usedL[i]) ansL.push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
        if (usedR[i]) ansR.push_back(i + 1);
    }
    cout << ansL.size() + ansR.size() << '\n';
    cout << ansL.size() << ' ';
    for (size_t i = 0; i < ansL.size(); ++i) {
        cout << ansL[i] << ' ';
    }
    cout << '\n' << ansR.size() << ' ';
    for (size_t i = 0; i < ansR.size(); ++i) {
        cout << ansR[i] << ' ';
    }
    return 0;
}

