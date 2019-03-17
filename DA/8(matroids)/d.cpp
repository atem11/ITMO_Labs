#include <bits/stdc++.h>

using namespace std;

vector<int> M;
int n, m;
bool aks1 = true, aks2, aks3, Mask[2000];

bool check(int M1, int M2) {
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; ++i) {
        if ((M1 & (1 << i)) != 0) {
            k1++;
        }
        if ((M2 & (1 << i)) != 0) {
            k2++;
        }
    }
    if (k1 == k2) {
        return true;
    }
    if (k1 < k2) {
        swap(M1, M2);
    }
    for (int i = 0; i < n; ++i) {
        if (((M1 & (1 << i)) != 0) && ((M2 & (1 << i)) == 0)) {
            if (Mask[M2 | (1 << i)])
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);//*/
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int k, msk = 0;
        cin >> k;
        if (k == 0) {
            aks1 = false;
        }
        for (int j = 0; j < k; ++j) {
            int b;
            cin >> b;
            msk += (1 << (b - 1));
        }
        M.push_back(msk);
        Mask[msk] = true;
    }
    for (int i = 0; i < M.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (((1 << j) & M[i]) != 0 && (!Mask[M[i] ^ (1 << j)])) {
                aks2 = true;
                break;
            }
        }
    }
    for (int i = 0; i < M.size(); ++i) {
        for (int j = i + 1; j < M.size(); ++j) {
            if (!check(M[i], M[j])) {
                aks3 = true;
                break;
            }
        }
    }
    if (!aks1 && !aks2 && !aks3) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}


