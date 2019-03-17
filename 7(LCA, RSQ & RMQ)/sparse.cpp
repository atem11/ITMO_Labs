#include <bits/stdc++.h>

using namespace std;

int n, m, a, u, v;
vector<int> mas, st, poww;
vector<vector<int> > sparse;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);
    cin >> n >> m >> a >> u >> v;
    st.resize(n + 1);
    st[1] = 0;
    for (int  i = 0; i < n; i++) {
        mas.push_back(a);
        a = (23 * a + 21563) % 16714589;
    }
    int p = 1;
    for (int i = 2; i <= n; i++) {
        if (p * 2 > i) {
            st[i] = st[i - 1];
        } else {
            p *= 2;
            st[i] = st[i - 1] + 1;
        }
    }
    p = 1;
    while (p <= n) {
        poww.push_back(p);
        p *= 2;
    }
    sparse.resize(st[n] + 1);
    for (int i = 0; i < n; i++) {
        sparse[0].push_back(mas[i]);
    }
    p = 1;
    for (int i = 1; i <= st[n]; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 2 * p <= n) sparse[i].push_back(min(sparse[i - 1][j], sparse[i - 1][j + p]));
        }
        p *= 2;
    }
    int u1 = u - 1, v1 = v - 1;
    if (u > v) swap(u1, v1);
    int l = v1 - u1 + 1;
    int ans = min(sparse[st[l]][u1], sparse[st[l]][u1 + (l - poww[st[l]])]);
    for (int i = 1; i < m; i++) {
        u = (17 * u + 751 + ans + 2 * i) % n + 1;
        v = (13 * v + 593 + ans + 5 * i) % n + 1;
        u1 = u - 1;
        v1 = v - 1;
        if (u > v) swap(u1, v1);
        l = v1 - u1 + 1;
        ans = min(sparse[st[l]][u1], sparse[st[l]][u1 + (l - poww[st[l]])]);
    }
    cout << u << ' ' << v << ' ' <<  ans;
    return 0;
}
