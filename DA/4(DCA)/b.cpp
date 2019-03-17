#include <bits/stdc++.h>

using namespace std;

string str;
int n, m, k;
vector<vector<vector<int> > > automat;
bool ext[100], use[100], ans = false;

void dfs(int v, int ind) {
    if (!ans) {
        if (ind == str.length()) {
            if (ext[v]) ans = true;
            return;
        }
        char ch = str[ind];
        for (int i = 0; i < automat[v][ch - 'a'].size(); i++) {
            dfs(automat[v][ch - 'a'][i], ind + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    cin >> str;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        ext[x - 1] = true;
    }
    automat.resize(n);
    for (int i = 0; i < n; i++) {
        automat[i].resize(26);
    }
    char ch = str[str.length() - 1];
    bool check = true;
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--;
        b--;
        automat[a][c - 'a'].push_back(b);
        if (ext[b] && c == ch) check = false;
    }
    if (check) {
        cout <<  "Rejects" << '\n';
        return 0;
    }
    dfs(0, 0);
    if (ans) {
        cout <<  "Accepts" << '\n';
        return 0;
    }
    cout <<  "Rejects" << '\n';
    return 0;
}

