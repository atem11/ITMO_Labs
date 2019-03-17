#include <bits/stdc++.h>

using namespace std;

bool use[200];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nextsetpartition.in", "r", stdin);
    freopen("nextsetpartition.out", "w", stdout);
    int n = 1, k = 1;
    string S;
    while(1)
    {
        getline(cin, S);
        stringstream Str;
        Str << S;
        Str >> n >> k;
        if (n == 0)
            break;
        for (int i = 0; i <= n; i++)
            use[i] = 0;
        vector<vector<int> > ans;
        for (int i = 0; i < k; i++)
        {
            vector<int> s;
            int x;
            string ss;
            getline(cin, ss);
            stringstream str;
            str << ss;
            while(str >> x)
                s.push_back(x);
            ans.push_back(s);
        }
        getline(cin, S);

        for (int i = k - 1; i >= 0; i--)
        {
            bool f = 0;
            int N = ans[i].size() - 1, Ad = -1;
            for (int i1 = ans[i][N] + 1; i1 <= n; i1++)
                if (use[i1])
                {
                    Ad = i1;
                    use[Ad] = 0;
                    break;
                }
            if (Ad != -1)
            {
                ans[i].push_back(Ad);
                break;
            }

            for (int j = N; j >= 0; j--)
            {
                if (j == 0)
                {
                    use[ans[i][j]] = 1;
                    ans.pop_back();
                }
                else
                {
                    bool del = 1;
                    for (int i1 = ans[i][j] + 1; i1 <= n; i1++)
                        if (use[i1])
                        {
                            del = 0;
                            use[i1] = 0;
                            use[ans[i][j]] = 1;
                            ans[i][j] = i1;
                            break;
                        }
                    if (del)
                    {
                        use[ans[i][j]] = 1;
                        ans[i].pop_back();
                    }
                    else
                    {
                        f = 1;
                        break;
                    }
                }
            }
            if (f)
                break;
        }
        for (int j = 1; j <= n; j++)
        {
            if (use[j])
            {
                vector<int> s;
                s.push_back(j);
                ans.push_back(s);
            }
        }

        cout << n << ' ' << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';

    }
    return 0;
}
