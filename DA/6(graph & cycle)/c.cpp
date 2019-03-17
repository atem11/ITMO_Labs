#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> mas;

bool ans(int a, int b) {
    cout << 1 << ' ' << a << ' ' << b << '\n';
    cout.flush();
    string s;
    cin >> s;
    return (s == "NO");
}

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
                    if (ans(mas[uk1], mas[uk2]))
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    mas.resize(n);
    for (int i = 0; i < n; ++i) {
        mas[i] = i + 1;
    }
    merg(0, n - 1);
    cout << 0 << ' ';
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << ' ';
    }
    cout.flush();
    return 0;
}

