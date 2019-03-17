#include <bits/stdc++.h>

using namespace std;

struct ver
{
    int m, g;
    vector<int> s;
    vector<int> ans;
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> lst, answer, deep(n);
    vector<ver> circuit(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        circuit[i].m = m;
        if (m == 0)
        {
            lst.push_back(i);
            circuit[i].g = 0;
            continue;
        }
        int M = 0;
        for (int j = 0; j < m; j++)
        {
            int s;
            cin >> s;
            s--;
            M = max(M, circuit[s].g);
            circuit[i].s.push_back(s);
        }
        circuit[i].g = M + 1;
        m = 1 << m;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            circuit[i].ans.push_back(x);
        }
    }
    cout << circuit[n - 1].g << '\n';
    answer.resize(n);
    for (int i = 0; i < (1 << lst.size()); i++)
    {
        int trsh = i;
        for (int j = lst.size() - 1; j >= 0; j--)
        {
            answer[lst[j]] = trsh % 2;
            trsh /= 2;
        }
        for (int j = 0; j < n; j++)
            if (circuit[j].m != 0)
            {
                trsh = 0;
                for (int i1 = 0; i1 < circuit[j].s.size(); i1++)
                {
                    trsh *= 2;
                    trsh += answer[circuit[j].s[i1]];
                }
                answer[j] = circuit[j].ans[trsh];
            }
        cout << answer[n - 1];
    }
    return 0;
}
