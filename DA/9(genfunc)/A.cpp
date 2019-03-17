#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int P, Q;
    cin >> P >> Q;
    long long p[P + 1], q[Q + 1];
    for (int i = 0; i <= P; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i <= Q; ++i) {
        cin >> q[i];
    }

    vector<long long> p_plus_q;
    for (int i = 0; i <= min(P, Q); ++i) {
        p_plus_q.push_back((p[i] + q[i]) % MOD);
    }
    if (P > Q) {
        for (int i = Q + 1; i <= P; ++i) {
            p_plus_q.push_back(p[i]);
        }
    } else if (Q > P) {
        for (int i = P + 1; i <= Q; ++i) {
            p_plus_q.push_back(q[i]);
        }
    }
    while (p_plus_q[p_plus_q.size() - 1] == 0) {
        p_plus_q.pop_back();
    }
    if (p_plus_q.size() == 0) {
        cout << 0 << '\n' << 0 << '\n';
    } else {
        cout << p_plus_q.size() - 1 << '\n';
        for (auto i : p_plus_q) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    vector<long long> p_mull_q;
    for (int i = 0; i <= P + Q; ++i) {
        long long res = 0;
        for (int st_p = 0; st_p <= i; ++st_p) {
            int st_q = i - st_p;
            if (st_p <= P && st_q <= Q) {
                res = (res + p[st_p] * q[st_q]) % MOD;
            }
        }
        p_mull_q.push_back(res);
    }
    while (p_mull_q[p_mull_q.size() - 1] == 0) {
        p_mull_q.pop_back();
    }
    if (p_mull_q.size() == 0) {
        cout << 0 << '\n' << 0 << '\n';
    } else {
        cout << p_mull_q.size() - 1 << '\n';
        for (auto i : p_mull_q) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    vector<long long> p_div_q;
    p_div_q.assign(1000, 0);
    for (int i = 0; i < 1000; ++i) {
        long long sum = 0;
        for (int j = 1; j <= i; ++j) {
            long long a = 0;
            long long b = p_div_q[i - j];
            if (j <= Q) {
                a = q[j];
            }
            sum += a * b;
            sum %= MOD;
        }
        long long c = 0;
        if (i <= P) {
            c = p[i];
        }
        p_div_q[i] = ((c + MOD - sum) / q[0]) % MOD;
    }
    for (auto i : p_div_q) {
        cout << i << ' ';
    }

    return 0;
}
