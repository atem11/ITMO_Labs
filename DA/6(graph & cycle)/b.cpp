#include <bits/stdc++.h>

using namespace std;

int g[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    freopen("chvatal.in", "r", stdin);
    freopen("chvatal.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 1; i < n; ++i) {
        V[i] = i;
        string s;
        cin >> s;
        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] == '1') {
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }
    }
    random_shuffle(V.begin(), V.end());
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        q.push_back(V[i]);
    }
    int u, v;
    for (int k = 0; k < n * (n - 1); ++k) {
        u = q.front();
        q.pop_front();
        v = q.front();
        if (!g[u][v]) {
            queue<int> sw;
            sw.push(q.front());
            q.pop_front();
            bool f = false;
            int u1, v1;
            while (!f) {
                u1 = q.front();
                q.pop_front();
                //v1 = q.front();
                sw.push(u1);
                if (g[u][u1]/* && g[v][v1]*/) {
                    f = true;
                }
            }
            /*if (q.empty()) {
                while(!sw.empty()) {
                    q.push_front(sw.front());
                    sw.pop();
                }
                while (!f) {
                    u1 = q.front();
                    q.pop_front();
                    sw.push(u1);
                    if (g[u][u1]) {
                        f = true;
                    }
                }
            }*/
            while(!sw.empty()) {
                    q.push_front(sw.front());
                    sw.pop();
                }
        }
        q.push_back(u);
    }
    while (!q.empty()) {
        cout << q.front() + 1 << ' ';
        q.pop_front();
    }
    return 0;
}

