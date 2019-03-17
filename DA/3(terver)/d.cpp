#include <bits/stdc++.h>

using namespace std;

bool absorbing[400];
double R[400][400], Q[400][400], E[400][400], N[400][400], G[400][400], input1[160000];
int input[160000][2], position[400];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("absmarkchain.in", "r", stdin);
    freopen("absmarkchain.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> input[i][j];
        }
        cin >> input1[i];
    }
    int abs = 0;
    for (int i = 0; i < m; i++)
    {
        if (input[i][0] == input[i][1] && input1[i] == 1.0)
        {
            absorbing[input[i][0] - 1] = true;
            abs++;
        }
    }
    int q = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (absorbing[i])
        {
            position[i] = r;
            r++;
        }
        else
        {
            position[i] = q;
            q++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (absorbing[input[i][1] - 1] == true)
        {
            if (absorbing[input[i][0] - 1] == false)
                R[position[input[i][0] - 1]][position[(input[i][1]) - 1]] = input1[i];
        }
        else
            Q[position[input[i][0] - 1]][position[input[i][1] - 1]] = input1[i];
    }
    int nonabs = n - abs;

    for (int i = 0; i < nonabs; i++)
    {
        N[i][i] = 1.0;
        E[i][i] = 1.0;
        for (int j = 0; j < nonabs; j++)
            E[i][j] -= Q[i][j];
    }
    double mul;
    for (int i = 0; i < nonabs; i++)
    {
        if (E[i][i] != 1)
        {
            mul = E[i][i];
            for (int j = 0; j < nonabs; j++)
            {
                E[i][j] /= mul;
                N[i][j] /= mul;
            }
        }
        for (int row = 0; row < nonabs; row++)
        {
            if (i != row)
            {
                mul = E[row][i];
                for (int j = 0; j < nonabs; j++)
                {
                    E[row][j] -= (mul * E[i][j]);
                    N[row][j] -= (mul * N[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < nonabs; i++)
    {
        for (int j = 0; j < abs; j++)
        {
            for (int k = 0; k < nonabs; k++)
                G[i][j] += N[i][k] * R[k][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        double prob = 0.0;
        if (absorbing[i] == true)
        {
            for (int j = 0; j < nonabs; j++)
                prob += G[j][position[i]];
                prob += 1.0;
                prob /= n;
        }
        cout.precision(5);
        cout << fixed << prob << "\n";
    }
    return 0;
}
