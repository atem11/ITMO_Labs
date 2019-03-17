#include <bits/stdc++.h>

using namespace std;

vector<int> cycle;
int ans = 0, sz = 0;

bool not_indep(int M) {
    for (int i = 0; i < cycle.size(); ++i) {
        if ((M & cycle[i]) == cycle[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("cycles.in", "r", stdin);
    freopen("cycles.out", "w", stdout);//*/
    int n, m;
    cin >> n >> m;
    int w[n];
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < m; ++i) {
        int k, msk = 0;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int b;
            cin >> b;
            msk += (1 << (b - 1));
        }
        cycle.push_back(msk);
    }
    for (int i = (1 << n) - 1; i >= 0; --i) {
        if (not_indep(i)) {
            int cnt = 0, W = 0;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    cnt++;
                    W += w[j];
                }
            }
            if (cnt > sz) {
                sz = cnt;
                ans = W;
            } else if (cnt == sz && ans < W) {
                ans = W;
            }
        }
    }
    cout << ans;
    return 0;
}

