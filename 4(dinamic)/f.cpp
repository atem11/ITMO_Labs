#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string A, B;
    getline(cin, A);
    getline(cin, B);
    A = A;
    B = B;
    vector<vector<bool> > dp;
    int M = (int)B.size() + 1, N = (int)A.size() + 1;
    dp.resize(M);
    dp[0].push_back(1);
    bool f = 1;
    for (int i = 1; i < N; i++)
        if (f && A[i - 1] == '*')
            dp[0].push_back(1);
        else
        {
            f = 0;
            dp[0].push_back(0);
        }
    for (int i = 1; i < M; i++)
        for (int j = 0; j < N; j++)
            dp[i].push_back(0);

    /*for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }*/

    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            int eq = 0;
            if (A[j - 1] == B[i - 1])
                eq = 1;
            if (A[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1];
            if (A[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            if (A[j - 1] != '*' && A[j - 1] != '?')
                dp[i][j] = dp[i - 1][j - 1] & eq;
        }
    }
    /*for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }*/
    if (dp[M - 1][N - 1])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
