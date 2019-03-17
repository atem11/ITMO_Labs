#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    n = 1 << n;
    pair<string, int> polinom[n];
    int znach[n];
    for (int i = 0; i < n; i++)
        cin >> polinom[i].first >> znach[i];
    for (int i = 0; i < n; i++)
    {
        polinom[i].second = znach[0];
        for (int j = 0; j < n - i - 1; j++)
        {
            znach[j] = znach[j] ^ znach[j + 1];
        }
    }
    for (int i = 0; i < n; i++)
        cout << polinom[i].first << ' ' << polinom[i].second << '\n';
    return 0;
}
