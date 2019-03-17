#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<int> ans, use, answ, used;
bool cycle;

void dfs(int v) {
    use[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int u = g[v][i];
        if (use[u] == 1 || cycle == true) {
            cycle = true;
            return;
        }
        if (use[u] == 0) {
            dfs(u);
        }
    }
    use[v] = 2;
    ans.push_back(v);
}

int main() {
    //freopen("tiv.in", "r", stdin);
    //freopen("tiv.out", "w", stdout);
    int N = 26;
    g.resize(N);
    use.resize(N);
    used.resize(N);
    answ.resize(N);

    int n, m = 0;
    cin >> n;
    vector<vector<char> > word;
    word.resize(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s.size() > m) {
            m = s.size();
        }
        for (size_t j = 0; j < s.size(); ++ j) {
            word[i].push_back(s[s.size() - j - 1]);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (word[j].size() > i) {
                if (word[j][i] != word[j + 1][i]) {
                    g[word[j][i] - 'a'].push_back(word[j + 1][i] - 'a');
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (use[i] == 0) {
            dfs(i);
        }
    }
    if (cycle) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < N; i++) cout << ans[i] << ' ';
        cout << '\n';
        int mn = 0;
        for (int i = 0; i < N; ++i) {
            cout << g[ans[i]].size() << ' ';
            if (g[ans[i]].size() != 0) {
                mn++;
                answ[ans[i]] = mn;
                used[mn] = 1;
            }
        }
        for (int i = 0; )
        cout << '\n';
        for (int i = 0; i < N; i++) cout << answ[i] << ' ';
    }
    return 0;
}

