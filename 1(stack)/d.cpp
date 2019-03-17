#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next;
};

struct my_queue
{
    int qsize = 0;
    node *head = NULL, *tail = NULL;
    void push(int new_value)
    {
        if (qsize == 0)
        {
            head = tail = (node*)malloc(sizeof(node));
            head -> value = new_value;
        }
        else
        {
            tail -> next = (node*)malloc(sizeof(node));
            tail = tail -> next;
            tail -> value = new_value;
        }
        qsize++;
    }
    int pop()
    {
        int new_value = head -> value;
        node *trash_head = head -> next;
        free(head);
        head = trash_head;
        qsize--;
        return new_value;
    }
};

int main()
{
    freopen("queue2.in", "r", stdin);
    freopen("queue2.out", "w", stdout);
    my_queue a;
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

