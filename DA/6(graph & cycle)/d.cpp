#include <bits/stdc++.h>

using namespace std;

int n;
int g[1000][1000];
vector<int> mas;

void merg(int l, int r)
{
    if (l == r) return;
    else
    {
        int mid = (l + r) / 2;
        merg(l, mid);
        merg(mid + 1, r);
        vector<int> b;
        b.resize(r - l + 1);
        int uk1 = l, uk2 = mid + 1;
        for (int i = 0; i < r - l + 1; i++)
        {
            if (uk1 > mid) b[i] = mas[uk2], uk2++;
            else
            {
                if (uk2 > r) b[i] = mas[uk1], uk1++;
                else
                {
                    if (g[mas[uk1]][mas[uk2]] == -1)
                    {
                        b[i] = mas[uk2];
                        uk2++;
                    }
                    else
                    {
                        b[i] = mas[uk1];
                        uk1++;
                    }
                }
            }
        }
        for (int i = l; i <= r; i++)
        {
            mas[i] = b[i - l];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("guyaury.in", "r", stdin);
    freopen("guyaury.out", "w", stdout);//*/
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        string s;
        cin >> s;
        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] == '1') {
                g[i][j] = 1;
                g[j][i] = -1;
            } else {
                g[i][j] = -1;
                g[j][i] = 1;
            }
        }
    }
    mas.resize(n);
    for (int i = 0; i < n; ++i) {
        mas[i] = i;
    }
    bool f = true;
    while (f) {
        random_shuffle(mas.begin(), mas.end());
        merg(0, n - 1);
        if (g[mas[0]][mas[n-1]] == -1) f = false;
    }
    for (int i = 0; i < n; ++i) {
        cout << mas[i] + 1 << ' ';
    }
    return 0;
}

