#include <bits/stdc++.h>

using namespace std;

long long const MOD = 1e9 + 7;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    ans = c;
    vector<int> pref, ekv;
    ekv.assign(n, 0);
    pref.resize(n);
    for (int i = 1; i < n; ++i) {
        cin >> pref[i];
    }
    int maxekv = 0;
    for (int i = 1; i < n; ++i) {
        if (pref[i] == 0) {
            set<int> used;
            int mb = pref[i - 1];
            used.insert(ekv[0]);
            while (mb > 0) {
                used.insert(ekv[mb]);
                mb = pref[mb - 1];
            }
            ekv[i] = ++maxekv;
            long long cnt = (long long)(c - used.size());
            ans = ans * cnt % MOD;
        } else {
            ekv[i] = ekv[pref[i] - 1];
        }
    }
    cout << ans << '\n';
    return 0;
}
