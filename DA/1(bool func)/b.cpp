#include <bits/stdc++.h>

using namespace std;

bool is_true[100];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    bool is_0 = 0;
    int lit[m][n], cnt[m], pod[n];
    for (int i  = 0; i < n; i++)
        pod[i] = -1;
    for (int i = 0; i < m; i++)
    {
        int kol = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> lit[i][j];
            if (lit[i][j] != -1) kol++;
        }
        if (kol == 1) is_0 = 1;
        cnt[i] = kol;
    }
    bool breaker = 1;
    while (is_0)
    {
        if (!breaker) break;
        int cnt_lit = 0;
        for (int i = 0; i < m; i++)
        {
            if(!breaker) break;
            if (cnt[i] == 1 && !is_true[i])
            {
                cnt_lit++;
                int ind = 0;
                for(int j = 0; j < n; j++)
                    if (lit[i][j] != -1)
                    {
                        ind = j;
                        break;
                    }
                pod[ind] = lit[i][ind];
                is_true[i] = 1;
                for (int j = 0; j < m; j++)
                    if(!is_true[j])
                    {
                        if(cnt[j] == 1 && lit[j][ind] != -1 && lit[j][ind] != pod[ind])
                        {
                            breaker = 0;
                            break;
                        }
                        if(lit[j][ind] == pod[ind]) is_true[j] = 1;
                        else
                        {
                            if (lit[j][ind] != -1)
                            {
                                lit[j][ind] = -1;
                                cnt[j]--;
                            }
                        }
                    }
            }
        }
        if (cnt_lit == 0) is_0 = 0;
    }
    if (is_0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
