#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 2e4 + 5;
const int INF = 1e5;

struct edge {
    int a, b, cap, flow;
};

int n, nL, nR, m, s = 0, t;
vector<int> d, ptr;
vector<edge> e;
vector<int> g[MAXN];

void assig() {
    for (int i = 0; i < MAXN; ++i) {
        g[i].resize(0);
    }
}

void add_edge (int a, int b, int cap) {
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);
}

bool bfs() {
    queue<int> q;
    q.push(s);
    d.assign(n, -1);
    d[s] = 0;
    while (!q.empty() && d[t] == -1) {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); ++i) {
            int id = g[v][i], to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]], to = e[id].b;
        if (d[to] != d[v] + 1) {
            continue;
        }
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic()
{
    int flow = 0;
    while(true) {
        if (!bfs()) {
            break;
        }
        ptr.assign(n, 0);
        int addflow = dfs(s, INF);
        while (addflow) {
            flow += addflow;
            addflow = dfs(s, INF);
        }
    }
    return flow;
}

vector<bool> use, use1;
vector<vector<int> > dg;
vector<int> ans;

void Dfs(int v) {
    use1[v] = true;
    if (v > nL){
        ans.push_back(v - nL);
    }
    for (size_t i = 0; i < dg[v].size(); ++i) {
        int u = dg[v][i];
        if (!use1[u]) {
            Dfs(u);
        }
    }
}

int main() {
    while (scanf("%d%d%d", &nL, &nR, &m) == 3) {
        t = nR + nL + 1;
        n = t + 1;
        e.resize(0);
        assig();
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            v += nL;
            add_edge(v, u, 1);
        }
        for (int i = 0; i < nR; ++i) {
            add_edge(s, i + nL + 1, 1);
        }
        for (int i = 0; i < nL; ++i) {
            add_edge(i + 1, t, 1);
        }
        if (dinic() == nR) {
            printf("0\n\n");
        } else {
            use.assign(n, false);
            use1.assign(n, false);
            ans.resize(0);
            dg.resize(0);
            dg.resize(n);
            for (int i = 0; i < 2 * m; i += 2) {
                if (e[i].flow == 1) {
                    dg[e[i].b].push_back(e[i].a);
                    use[e[i].a] = true;
                } else {
                    dg[e[i].a].push_back(e[i].b);
                }
            }
            for (int i = nL + 1; i <= nL + nR; ++i) {
                if (!use[i] && !use1[i]) {
                    Dfs(i);
                }
            }
            printf("%d\n", ans.size());
            sort(ans.begin(), ans.end());
            for(size_t i = 0; i < ans.size(); ++i) {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
