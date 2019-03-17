#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node
{
    ll value;
    node *next;
    node()
    {
    }
    node(ll new_value, node *new_next)
    {
        value = new_value;
        next = new_next;
    }
};

vector<node*> p;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    p.push_back(new node(0, NULL));
    for (int i = 0; i < n; i++)
    {
        int t;
        ll b;
        cin >> t >> b;
        if (b > 0)
        {
            p.push_back(new node(p[t] -> value + b, p[t]));
        }
        else
        {
            p.push_back(p[t] -> next);
        }
    }
    ll sum = 0;
    for (int i = 0; i < int(p.size()); i++)
        sum += p[i] -> value;
    cout << sum << '\n';
    return 0;
}
