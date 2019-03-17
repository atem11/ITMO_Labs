#include <bits/stdc++.h>

using namespace std;

const int N = 400000008;

int num[N];
vector<pair<long long, int> > my_queue;

void up(int v)
{
    if (v > 1 && my_queue[v / 2].first > my_queue[v].first)
    {
        swap(num[my_queue[v / 2].second], num[my_queue[v].second]);
        swap(my_queue[v / 2], my_queue[v]);
        up(v / 2);
    }
}

void down(int v)
{
    if (2 * v == int(my_queue.size()) - 1)
    {
        if (my_queue[v].first > my_queue[2 * v].first)
        {
            swap(num[my_queue[v].second], num[my_queue[2 * v].second]);
            swap(my_queue[v], my_queue[2 * v]);
        }
    }
    else
       if (2 * v + 1 < int(my_queue.size()))
        {
            if (my_queue[v].first > my_queue[2 * v + 1].first && my_queue[2 * v + 1].first < my_queue[2 * v].first)
            {
                swap(num[my_queue[v].second], num[my_queue[2 * v + 1].second]);
                swap(my_queue[v], my_queue[2 * v + 1]);
                down(2 * v + 1);
            }
            else
                if (my_queue[v].first > my_queue[2 * v].first && my_queue[2 * v].first <= my_queue[2 * v + 1].first)
                {
                    swap(num[my_queue[v].second], num[my_queue[2 * v].second]);
                    swap(my_queue[v], my_queue[2 * v]);
                    down(2 * v);
                }
        }
}

void extract_min()
{
    if (my_queue.size() == 1) cout << '*' << '\n';
    else
    {
        cout << my_queue[1].first << '\n';
        swap(num[my_queue[1].second], num[my_queue[my_queue.size() - 1].second]);
        swap(my_queue[1], my_queue[my_queue.size() - 1]);
        my_queue.pop_back();
        down(1);
    }
}

void push(long long key, int ind)
{
    my_queue.push_back({key, ind});
    int i = my_queue.size() - 1;
    num[ind] = i;
    up(i);
    //for (int k = 0; k < my_queue.size(); k++)
      //  cout << my_queue[k].first << ' ';
    //cout << '\n';
}

void decrease_key(int nm, long long key)
{
    int v = num[nm];
    if (my_queue[v].first > key)
    {
        my_queue[v].first = key;
        up(v);
    }
    else
    {
        my_queue[v].first = key;
        down(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    string s;
    my_queue.push_back({-1, -1});
    int uk = 0;
    while(cin >> s)
    {
        uk++;
        if (s == "push")
        {
            long long x;
            cin >> x;
            push(x, uk);
        }
        if (s == "decrease-key")
        {
            int x;
            long long y;
            cin >> x >> y;
            decrease_key(x, y);
        }
        if (s == "extract-min")
            extract_min();
    }
    return 0;
}
