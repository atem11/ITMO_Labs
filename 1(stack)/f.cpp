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
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    my_stack a = my_stack();
    char c;
    while(scanf("%c ", &c) == 1)
    {
        if (c != '+' && c != '-' && c != '*') a.push((int)(c - '0'));
        else
        {
            int x, y;
            x = a.pop();
            y = a.pop();
            if (c == '+')
                a.push(x + y);
            if (c == '-')
                a.push(y - x);
            if (c == '*')
                a.push(x * y);
        }
    }
    printf("%d\n", a.pop());
    return 0;
}


