#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<vector<int> > > Rautomat, DRautomat, RDRautomat, DRDRautomat;
vector<int> ext, strt;

vector<vector<int> > deter(vector<vector<vector<int> > > newautomat) {
    vector<vector<int> > automat(n);
    queue<set<int> > q;
    set<int> st;
    for (int i = 0; i < strt.size(); i++) {
        st.insert(strt[i]);
    }
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
    return automat;
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("fastminimization.in", "r", stdin);
    //freopen("fastminimization.out", "w", stdout);
    cin >> n >> m >> k;
    ex
    return 0;
}
