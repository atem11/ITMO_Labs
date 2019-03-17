#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    int ind;
    node *next, *prev;
};

struct my_deque
{
    int dsize = 0;
    node *head = NULL, *tail = NULL;
    void push(int new_value, int new_ind)
    {
        if (dsize == 0)
        {
            head = tail = (node*)malloc(sizeof(node));
            head -> value = new_value;
            head -> ind = new_ind;
        }
        else
        {
            tail -> next = (node*)malloc(sizeof(node));
            (tail -> next) -> prev = tail;
            tail = tail -> next;
            tail -> value = new_value;
            tail -> ind = new_ind;
        }
        qsize++;
    }
    pair<int, int> pop_f1()
    {
        int new_value = head -> value;
        int new_ind = head -> ind;
        return {new_value, new_ind};
    }
    void pop_f2()
    {
        node *trash_head = head -> next;
        free(head);
        head = trash_head;
        qsize--;
    }
    pair<int, int> pop_b1()
    {
        int new_value = tail -> value;
        int new_ind = tail -> ind;
        return {new_value, new_ind};
    }
    void pop_b2()
    {
        node *trash_tail = tail -> prev;
        free(tail);
        tail = trash_tail;
        qsize--;
    }
};

int main()
{
    //freopen("queuemin2.in", "r", stdin);
    //freopen("queuemin2.out", "w", stdout);
    my_deque a;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int a, b, c;
    int ans = 0;
    int x, y;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 0; i < n; i++)
    {
        if (k > 0) scanf()
    }
    return 0;
}


