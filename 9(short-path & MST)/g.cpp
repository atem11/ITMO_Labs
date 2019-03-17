#include <bits/stdc++.h>

using namespace std;

const int N = 5009;
const int INF = 2e9 + 7;

struct dot{
    int x, y;
};

bool used[N];
int d[N];
dot V[N];
double ans;

int way(dot a, dot b) {
    return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        d[i] = INF;
        cin >> V[i].x >> V[i].y;
    }
    d[n] = INF + 5;
    d[0] = 0;
    int w = 0;
    for (int i = 0; i < n; ++i) {
        int u = n;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && d[j] < d[u]) {
                u = j;
            }
        }
        ans += sqrt(d[u]);
        used[u] = true;
        for (int j = 0; j < n; ++j) {
            w = way(V[j], V[u]);
            if (!used[j] && d[j] > w) {
                d[j] = w;
            }
        }
    }
    cout.precision(15);
    cout << fixed << ans << '\n';
    return 0;
}

