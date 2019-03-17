#include <bits/stdc++.h>

using namespace std;

int SZ = 16777216;
unsigned int t[16777217];

unsigned int a, b, cur = 0;
unsigned int nextRand() {
     cur = cur * a + b;
     return cur >> 8;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("fastadd.in", "r", stdin);
    freopen("fastadd.out", "w", stdout);
    int n, m;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; i++) {
        unsigned int add = nextRand(),
        l = nextRand(),
        r = nextRand();
        if (l > r) swap(l, r);
        t[l] += add;
        t[r + 1] -= add;
    }
    for (int i = 0; i < SZ; i++) {
        t[i + 1] += t[i];
    }
    for (int i = 0; i < SZ; i++) {
        t[i + 1] += t[i];
    }
    unsigned int res = 0;
    for (int i = 0; i < n; i++) {
        unsigned int l = nextRand(),
        r = nextRand();
        if (l > r) swap(l, r);
        res += t[r];
        if (l > 0) res -= t[l - 1];
    }
    cout << res;
    return 0;
}
