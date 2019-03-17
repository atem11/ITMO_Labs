#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 33;
long long p = 53;
vector<long long> hs;
vector<long long> my_pow;

void my_hash(string s) {
    my_pow.resize(s.size());
    my_pow[0] = 1;
    for (size_t i = 1; i < my_pow.size(); ++i) {
        my_pow[i] = my_pow[i - 1] * p % MOD;
    }
    long long res = 0;
    int sz = (int)s.length();
    hs.resize(sz);
    for (int i = 0; i < sz; ++i) {
        res = (res + s[i] * my_pow[i]) % MOD;
        hs[i] = res;
    }
}

long long getsubstr(int l, int r) {
    long long tmp = 0;
    if (l != 0) {
        tmp = hs[l - 1];
    }
    long long res = (hs[r] + MOD - tmp) % MOD;
    res = res * my_pow[(int)my_pow.size() - r - 1] % MOD;
    return res;
}

int main() {
     //*
    freopen("substrcmp.in", "r", stdin);
    freopen("substrcmp.out", "w", stdout);
    //*/
    string s;
    cin >> s;
    my_hash(s);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        --l1;
        --r1;
        --l2;
        --r2;
        if (getsubstr(l1, r1) == getsubstr(l2, r2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
