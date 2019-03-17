#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next;
    node()
    {
    }
    node(int new_value, node *new_next)
    {
        value = new_value;
        next = new_next;
    }
};

struct my_stack
{
    node *head = NULL;
    void push(int new_value)
    {
        head = new node(new_value, head);
    }
    int pop()
    {
        int new_value = head -> value;
        node *trash_head = head -> next;
        free(head);
        head = trash_head;
        return new_value;
    }
};

int main()
{
    freopen("stack2.in", "r", stdin);
    freopen("stack2.out", "w", stdout);
    my_stack a;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int y;
        char x;
        scanf("\n%c", &x);
        if (x == '+')
        {
            scanf("%d", &y);
            a.push(y);
        }
        else
        {
            printf("%d\n", a.pop());
        }
    }
    return 0;
}
