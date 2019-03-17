#include <bits/stdc++.h>

using namespace std;

unsigned int cur = 0, a, b, n, m;
vector<unsigned int> mas;

unsigned int nextRand24()
{
    cur = cur * a + b;
    return cur >> 8;
}

unsigned long long ans = 0;

void merg(int l, int r)
{
    if (l == r) return;
    else
    {
        int mid = (l + r) / 2;
        merg(l, mid);
        merg(mid + 1, r);
        vector<unsigned int> b;
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
                    if (mas[uk1] > mas[uk2])
                    {
                        ans += (mid - uk1 + 1);
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
    freopen("invcnt.in", "r", stdin);
    freopen("invcnt.out", "w", stdout);
    cin >> n >> m >> a >> b;
    for (int i = 0; i < (int)n; i++)
        mas.push_back(nextRand24() % m);
    merg(0, n - 1);
    cout << ans;
    return 0;
}
