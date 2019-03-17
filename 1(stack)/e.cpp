#include <bits/stdc++.h>

using namespace std;

struct node
{
    char value;
    node *next;
    node()
    {
    }
    node(char new_value, node *new_next)
    {
        value = new_value;
        next = new_next;
    }
};

struct my_stack
{
    int ssize;
    node *head;

    my_stack() : ssize(0), head(NULL) {  }
    void push(char new_value)
    {
        head = new node(new_value, head);
        ssize++;
    }
    char pop()
    {
        char new_value = head -> value;
        node *trash_head = head -> next;
        free(head);
        head = trash_head;
        ssize--;
        return new_value;
    }
};

int main()
{
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    my_stack a = my_stack();
    char c;
    while(scanf("%c", &c) == 1)
    {
        if (c == '\n')
        {
            if (a.ssize == 0) printf("YES\n");
            else printf("NO\n");
            a = my_stack();
        }
        else
        {
            if (c == '(' || c == '[') a.push(c);
            else
            {
                char x = ')';
                if (a.ssize != 0) x = a.pop();
                else a.push(c);
                if (c == ')' && x != '(')
                {
                    a.push(x);
                    a.push(c);
                }
                else
                    if(c == ']' && x != '[')
                    {
                        a.push(x);
                        a.push(c);
                    }
            }

        }
    }
    return 0;
}

