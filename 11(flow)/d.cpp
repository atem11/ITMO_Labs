#include <bits/stdc++.h>

using namespace std;

const int MAXN = 501;
const long long INF = 1e15;

struct edge {
    int a, b;
    long long cap, flow;
};

int n, m, s, t;
vector<int> d, ptr;
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, long long cap)
{
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);
}

bool bfs(long long a)
{
    queue<int> q;
    q.push(s);
    d.assign(n, -1);
    d[s] = 0;
    while (!q.empty() && d[t] == -1) {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); ++i) {
            int id = g[v][i], to = e[id].b;
            if (d[to] == -1 && e[id].cap - e[id].flow >= a) {
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

long long dfs (int v, long long flow)
{
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]], to = e[id].b;
        if (d[to] != d[v] + 1) {
            continue;
        }
        long long pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

long long dinic(long long a)
{
    long long flow = 0;
    while (a > 0) {
        while(true) {
            if (!bfs(a)) {
                break;
            }
            ptr.assign(n, 0);
            long long addflow = dfs(s, INF);
            while (addflow) {
                flow += addflow;
                addflow = dfs(s, INF);
            }
        }
        a /= 2;
    }
    return flow;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin >> n >> m;
    s = 0;
    t = n - 1;
    long long A = 1;
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long cap;
        cin >> a >> b >> cap;
        a--;
        b--;
        A = max(A, cap);
        add_edge(a, b, cap);
    }
    cout << dinic(A);
    return 0;
}

