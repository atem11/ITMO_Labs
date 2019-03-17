#include <bits/stdc++.h>

using namespace std;

unsigned int *a, *b;
int n, t;
unsigned int cur = 0, A, B;

unsigned int nextRand24()
{
    cur = cur * A + B;
    return cur >> 8;
}

unsigned int nextRand32()
{
    unsigned int a = nextRand24(), b = nextRand24();
    return (a << 8) ^ b;
}


void radix()
{
    unsigned int K = 131072;
    unsigned int c[131072];
    b = new unsigned int[n];
    for (int i = 0; i < 2; i++)
    {
        unsigned int d, d1;
        for (unsigned int j = 0; j < K; j++)
            c[j] = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                d1 = a[j] << 16;
                d = d1 >> 16;
            }
            else
            {
                d = a[j] >> 16;
            }
            c[d]++;
        }
        int cnt = 0;
        for (unsigned int j = 0; j < K; j++)
        {
            int t = c[j];
            c[j] = cnt;
            cnt += t;
        }
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                d1 = a[j] << 16;
                d = d1 >> 16;
            }
            else
            {
                d = a[j] >> 16;
            }
            b[c[d]] = a[j];
            c[d]++;
        }
        for (int j = 0; j < n; j++)
            a[j] = b[j];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    cin >> t >> n;
    cin >> A >> B;
    a = new unsigned int[n];
    for (int i1 = 0; i1 < t; i1++)
    {
        for (int i = 0; i < n; i++)
            a[i] = nextRand32();
        radix();
        unsigned long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += ((long long)a[i] * (long long)(i + 1));
        }
        cout << ans << '\n';
    }
    return 0;
}
