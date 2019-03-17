#include <bits/stdc++.h>

using namespace std;

int n, m, k, L;
vector<vector<int> > automat(1000000);
vector<int> ext, Null;
vector<vector<vector<int> > > newautomat;
bool ext1[100];
int dp[100][1003], mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);
    cin >> n >> m >> k >> L;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        ext1[x] = true;
    }
    newautomat.resize(n);
    for (int i = 0; i < n; i++) {
        newautomat[i].resize(26);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        newautomat[a][c - 'a'].push_back(b);
    }
    queue<set<int> > q;
    set<int> st;
    st.insert(0);
    map<set<int>, int> m;
    int I = 0;
    m[st] = I;
    if (ext1[0]) {
        ext.push_back(0);
    }
    q.push(st);
    while (!q.empty()) {
        st = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            set<int> newv;
            bool f = false;
            for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
                int v = (*it);
                for (int j = 0; j < newautomat[v][i].size(); j++) {
                    if (ext1[newautomat[v][i][j]]) f = true;
                    newv.insert(newautomat[v][i][j]);
                }
            }
            if (newv.size()) {
                if (m.count(newv) == 0) {
                    ++I;
                    m[newv] = I;
                    q.push(newv);
                    if (f) {
                        ext.push_back(I);
                    }
                }
                automat[m[st]].push_back(m[newv]);
            }
        }
    }
    for (int i = 0; i < ext.size(); i++) {
        dp[ext[i]][0] = 1;
    }
    for (int i = 1; i <= L; i++) {
        for (int j = 0; j <= I; j++) {
            for (int k = 0; k < automat[j].size(); k++) {
                dp[j][i] += dp[automat[j][k]][i - 1];
                dp[j][i] %= mod;
            }
        }
    }
    cout << dp[0][L] << '\n';
    return 0;
}

