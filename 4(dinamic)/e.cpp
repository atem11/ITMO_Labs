#include <bits/stdc++.h>

using namespace std;

int dp[5001][5001];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("levenshtein.in", "r", stdin);
    freopen("levenshtein.out", "w", stdout);
    string A, B;
    cin >> A >> B;
    int N = (int)B.size(), M = (int)A.size();
    for (int i = 1; i <= N; i++)
        dp[0][i] = i;
    for (int i = 1; i <= M; i++)
        dp[i][0] = i;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
        {
            int eq = 1;
            if (A[i - 1] == B[j - 1])
                eq = 0;
            dp[i][j] = min(dp[i - 1][j - 1] + eq, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
        }
    cout << dp[M][N];
    return 0;
}
