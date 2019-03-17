#include <bits/stdc++.h>

using namespace std;

unsigned int cur = 0, a, b, n;
long long k;
vector<long long> mas;

unsigned int nextRand24()
{
    cur = cur * a + b;
    return cur >> 8;
}

unsigned int nextRand32()
{
    unsigned int a = nextRand24(), b = nextRand24();
    return (a << 8) ^ b;
}

unsigned long long ans = 0;

void merg(int l, int r)
{
    if (l == r)
    {
        if (mas[l] >= k) ans++;
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        merg(l, mid);
        merg(mid + 1, r);
        vector<long long> b;
        b.resize(r - l + 1);
        int uk1 = l, uk2 = mid + 1;
        while (uk1 <= mid && uk2 <= r)
        {
            if (mas[uk2] - mas[uk1] >= k)
            {
                ans += r - uk2 + 1;
                if (uk1 < mid) uk1++;
                else break;
            }
            else
            {
                if (uk2 < r) uk2++;
                else uk1++;
            }
        }
        uk1 = l;
        uk2 = mid + 1;
        for (int i = 0; i < r - l + 1; i++)
        {
            if (uk1 > mid)
            {
                b[i] = mas[uk2];
                uk2++;
            }
            else
            {
                if (uk2 > r)
                {
                    b[i] = mas[uk1];
                    uk1++;
                }
                else
                {
                    if (mas[uk1] > mas[uk2])
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
    freopen("bigseg.in", "r", stdin);
    freopen("bigseg.out", "w", stdout);
    cin >> n >> k >> a >> b;
    for (int i = 0; i < (int)n; i++)
        mas.push_back((int)nextRand32());
    for (int i = 1; i < (int)n; i++)
        mas[i] = mas[i] + mas[i - 1];
    merg(0, n - 1);
    cout << ans;
    return 0;
}

