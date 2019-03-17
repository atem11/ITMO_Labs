#include <bits/stdc++.h>

using namespace std;

struct my_stack
{
    int *head = (int*)malloc(sizeof(int));
    int ssize = 1;
    int scount = 0;
    void push(int new_value)
    {
        if (scount > ssize - 1)
        {
            int *new_head = (int*)malloc((2 * ssize * sizeof(int)));
            for (int i = 0; i < ssize; i++)
                new_head[i] = head[i];
            head = new_head;
            ssize *= 2;
            //free(new_head);
        }
        head[scount] = new_value;
        scount++;
    }
    int pop()
    {
        int new_value = head[--scount];
        if (scount * 4 <= ssize && scount != 0)
        {
            int *new_head = (int*)malloc((ssize / 2 * sizeof(int)));
            for (int i = 0; i <= scount; i++)
                new_head[i] = head[i];
            head = new_head;
            ssize /= 2;
            //free(new_head);
        }
        return new_value;
    }
};

int main()
{
    freopen("stack1.in", "r", stdin);
    freopen("stack1.out", "w", stdout);
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
