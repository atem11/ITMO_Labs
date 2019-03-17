#include <bits/stdc++.h>

using namespace std;

int main() {
    //*
    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    s += "#";
    int n = (int)s.size();
    vector<pair<pair<int, int>, int> > T;
    vector<int> G(n), S(n);
    for( int i = 0; i < n; i++) {
        T.push_back({{s[i], 0}, i});
    }
    for (int i = 1; i < 2 * n; i *= 2) {
        sort(T.begin(), T.end());
        for(int j = 0, t = 0; j < n; j++) {
            t += (j > 0 && T[j].first != T[j - 1].first);
            G[T[j].second] = t;
        }
        for (int j = 0; j < n; j++) {
            T[j] = {{G[j], G[(j + i) % n]}, j};
        }
    }
    for(int i = 0; i < n; i++) {
        S[G[i]] = i;
    }
    for (int i = 1; i < n; i++)
        cout << S[i] + 1 << ' ';
    cout << '\n';
    return 0;
}

