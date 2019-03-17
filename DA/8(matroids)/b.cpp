#include <bits/stdc++.h>

using namespace std;

struct edge {
    int v, to;
    long long w;
    int num;
};

int parent[50003], sze[50003];

int find_parent(int v) {
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find_parent(parent[v]);
}

bool one_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    return a == b;
}

void union_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (sze[a] < sze[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sze[a] += sze[b];
    }
}

bool comp(edge a, edge b) {
    return a.w > b.w;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("destroy.in", "r", stdin);
    freopen("destroy.out", "w", stdout);//*/
    int n, m;
    long long s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sze[i] = 1;
    }
    vector<edge> edges;
    for (int i = 0; i < m; ++i) {
        int v, u;
        long long w;
        cin >> v >> u >> w;
        edges.push_back({v, u, w, i + 1});
    }
    sort(edges.begin(), edges.end(), comp);
    vector<int> not_ans, ans;
    for (int i = 0; i < m; ++i) {
        if (!one_set(edges[i].v, edges[i].to)) {
            union_set(edges[i].v, edges[i].to);
        } else {
            not_ans.push_back(i);
        }
    }
    long long S = 0;
    for (int i = not_ans.size() - 1; i >= 0; --i) {
        if (edges[not_ans[i]].w + S <= s) {
            S += edges[not_ans[i]].w;
            ans.push_back(edges[not_ans[i]].num);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}

