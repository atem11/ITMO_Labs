#include <bits/stdc++.h>

using namespace std;

int d, k;
vector<vector<int> > g;
vector<int> ans;
vector<string> code;
map<string, int> decode;
stack<int> q;
vector<bool> loop;

void gen(string cod) {
    if ((int)cod.size() == k - 1) {
        code.push_back(cod);
        decode.insert({cod, code.size() - 1});
        return;
    }
    for (int i = 0; i < d; ++i) {
        gen(cod + char('0' + i));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("codelock.in", "r", stdin);
    freopen("codelock.out", "w", stdout);//*/
    cin >> d >> k;
    if (k == 1) {
        for (int j = 0; j < d; ++j) {
            cout << char('0' + j);
        }
        return 0;
    }
    gen("");
    g.resize(code.size());
    loop.assign(code.size(), false);
    for (size_t i = 0; i < code.size(); ++i) {
        string s = "";
        for (size_t j = 1; j < code[i].size(); ++j) {
            s.push_back(code[i][j]);
        }
        string ns;
        for (int j = 0; j < d; ++j) {
            ns = s + char('0' + j);
            if (ns == code[i]) {
                loop[i] = true;
            } else {
                g[i].push_back(decode[ns]);
            }
        }
    }
    q.push(0);
    while (!q.empty()) {
        int v = q.top();
        if (loop[v]) {
            q.push(v);
            loop[v] = false;
        }
        while (g[v].size()) {
            int u = g[v][g[v].size() - 1];
            g[v].pop_back();
            q.push(u);
            break;
        }
        if (v == q.top()) {
            q.pop();
            ans.push_back(v);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << code[ans[0]];
    for (size_t i = 1; i < ans.size(); ++i) {
        cout << code[ans[i]][code[ans[i]].size() - 1];
    }
    return 0;
}

