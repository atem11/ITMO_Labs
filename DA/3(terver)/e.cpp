#include <bits/stdc++.h>

using namespace std;

int n;
double A[100][100], B[100][100];

bool check() {
    bool f = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (abs(A[j][i] - A[j + 1][i]) > 0.0001) {
                f = false;
                return f;
            }
        }
    }
    return f;
}

void pow1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double res = 0;
            for (int k = 0; k < n; k++) {
                res += (A[i][k] * A[k][j]);
            }
            B[i][j] = res;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double res = 0;
            for (int k = 0; k < n; k++) {
                res += (B[i][k] * B[k][j]);
            }
            A[i][j] = res;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("markchain.in", "r", stdin);
    freopen("markchain.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            B[i][j] = A[i][j];
        }
    }
    while (!check()) {
        pow1();
    }
    cout.precision(4);
    for (int i = 0; i < n; i++) {
        cout << fixed << A[0][i] << '\n';
    }
    return 0;
}
