#include <bits/stdc++.h>

using namespace std;

int g[1007][1007];
int use[1007];
int N, ans;

void dfs(int v) {
    use[v] = 1;
    for (int i = 0; i < N; ++i) {
        if (g[v][i] <= ans && !use[i]) dfs(i);
    }
}

void rdfs(int v) {
    use[v] = 1;
    for (int i = 0; i < N; ++i) {
        if (g[i][v] <= ans && !use[i]) rdfs(i);
    }
}

bool vised() {
    for (int i = 0; i < N; ++i) {
        if (!use[i]) return false;
    }
    return true;
}

void cl() {
    for (int i = 0; i < N; ++i) use[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("avia.in", "r", stdin);
    freopen("avia.out", "w", stdout);
    cin >> N;
    int mx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
            mx = max(mx, g[i][j]);
        }
    }
    int l = 0, r = mx + 1;
    while (l < r) {
        ans = (r + l) / 2;
        cl();
        dfs(0);
        if (vised()) {
            cl();
            rdfs(0);
            if (vised()) {
                r = ans;
            } else {
                l = ans + 1;
            }
        } else {
            l = ans + 1;
        }
    }
    cout << r << '\n';
    return 0;
}

