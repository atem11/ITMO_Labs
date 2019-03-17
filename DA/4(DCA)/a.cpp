#include <bits/stdc++.h>

using namespace std;

string str;
int n, m, k;
vector<map<char, int> > automat;
bool ext[100000];

int main() {
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
    cin >> str;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        ext[x - 1] = true;
    }
    automat.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--;
        b--;
        automat[a][c] = b;
    }
    int start = 0;
    bool ac = true;
    for (int i = 0; i < str.length(); i++) {
        char s = str[i];
        if (automat[start].count(s) > 0) {
            start = automat[start][s];
        } else {
            ac = false;
        }
        if (!ac) {
            break;
        }
    }
    if (!ext[start]) {
        ac = false;
    }
    if (ac) {
        cout << "Accepts" << '\n';
    } else {
        cout <<  "Rejects" << '\n';
    }
    return 0;
}
