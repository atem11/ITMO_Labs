#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int sz = 7;
vector<ll> const B = {0, 1, 0, 0, 0, 0, 0};
string input;
int ind = 0;

ll gcd (ll a, ll b) {
    if (a < b) {
        swap(a, b);
    }
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

ll C_n_k(ll n, ll k) {
    if (k == 0) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    ll res = 1;
    for (ll i = k + 1; i <= n; ++i) {
        res *= i;
    }
    for (ll i = 1; i <= n - k; ++i) {
        res /= i;
    }
    return res;
}

ll b(ll n, ll k, vector<ll> X) {
    if (k == 1) {
        return X[n];
    }
    ll res = 0;
    for (int i = 1; i < n; ++i) {
        res += (X[i] * b(n - i, k - 1, X));
    }
    return res;
}

ll St(ll n, ll s, ll i, vector<ll> X) {
    ll g = gcd(i, s);
    if (n % (s / g) != 0) {
        return 0;
    } else {
        return b(n * g / s, g, X);
    }
}

ll c(ll n, ll s, vector<ll> X) {
    ll res = 0;
    for (int i = 0; i < s; ++i) {
        res += (St(n, s, i, X));
    }
    return res / s;
}

vector<ll> L(vector<ll> X) {
    vector<ll> ans_L(sz, 0);
    ans_L[0] = 1;
    for (int i = 1; i < sz; ++i) {
        ans_L[i] = 0;
        for (int j = 1; j <= i; ++j) {
            ans_L[i] += X[j] * ans_L[i - j];
        }
    }
    return ans_L;
}

vector<ll> S(vector<ll> X) {
    vector<ll> ans_S(sz, 0);
    vector<vector<ll> > s(sz);
    for (int i = 0; i < sz; ++i) {
        s[i].resize(sz);
        s[i].assign(sz, 0);
    }
    for (int i = 0; i < sz; ++i) {
        s[i][0] = 0;
    }
    for (int i = 0; i < sz; ++i) {
        s[0][i] = 1;
    }
    for (int n = 1; n < sz; ++n) {
        for (int k = 1; k < sz; ++k) {
            for (int i = 0; i <= (n / k); ++i) {
                s[n][k] += C_n_k(X[k] + i - 1, i) * s[n - (i * k)][k - 1];
            }
        }
    }
    for (int  i = 0; i < sz; ++i) {
        ans_S[i] = s[i][i];
    }
    return ans_S;
}

vector<ll> P(vector<ll> X, vector<ll> Y) {
    vector<ll> ans_P(sz, 0);
    for (int i = 0; i < sz; ++i) {
        for(int j = 0; j <= i; ++j) {
            ans_P[i] += X[j] * Y[i - j];
        }
    }
    return ans_P;
}

vector<ll> C(vector<ll> X) {
    vector<ll> ans_C(sz);
    for (int n = 0; n < sz; ++n) {
        for (int s = 1; s <= n; ++s) {
            ans_C[n] += c(n, s, X);
        }
    }
    return ans_C;
}

vector<ll> parser() {
    vector<ll> ans;
    char ch = input[ind];
    switch (ch) {
        case 'B':
            ans = B;
            ind++;
            break;
        case 'L':
            ind += 2;
            ans = L(parser());
            ind++;
            break;
        case 'S':
            ind += 2;
            ans = S(parser());
            ind++;
            break;
        case 'C':
            ind += 2;
            ans = C(parser());
            ind++;
            break;
        case 'P':
            ind += 2;
            vector<ll> X = parser();
            ind++;
            vector<ll> Y = parser();
            ind++;
            ans = P(X, Y);
            break;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;
    vector<ll> ans = parser();
    for (int i = 0; i < sz; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}
