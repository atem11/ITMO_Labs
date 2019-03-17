#include <bits/stdc++.h>

using namespace std;

bool use[20];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    long long fact = 1;
    for (long long i = 2; i < n; i++)
        fact *= i;
    long long del = n - 1;
    for (long long j = 0; j < n - 1; j++)
    {
        long long uk = k / fact;
        k -= fact * uk;
        fact /= del;
        del--;
        for (long long i = 1; i <= n; i++)
        {
            if (uk == 0 && !use[i])
            {
                use[i] = 1;
                cout << i << ' ';
                break;
            }
            if (!use[i]) uk--;
        }
    }
    for (long long i = 1; i <= n; i++)
        if (!use[i])
        {
            cout << i;
            break;
        }
    return 0;
}



