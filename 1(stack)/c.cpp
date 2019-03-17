#include <bits/stdc++.h>

using namespace std;

struct my_queue
{
    int *head = (int*)malloc(sizeof(int));
    int h = 0, t = 0;
    int ssize = 1;
    void push(int new_value)
    {
        if (t > ssize - 1)
        {
            int *new_head = (int*)malloc((2 * ssize * sizeof(int)));
            for (int i = 0; i < ssize; i++)
                new_head[i] = head[i];
            head = new_head;
            ssize *= 2;
        }
        head[t] = new_value;
        t++;
    }
    int pop()
    {
        int new_value = head[h];
        h++;
        /*if ((t - h) * 4 <= ssize)
        {
            int *new_head = (int*)malloc((ssize / 2 * sizeof(int)));
            for (int i = 0; i <= (t - h); i++)
                new_head[i] = head[i + h];
            head = new_head;
            //free(new_head);
            ssize /= 2;
            t -= h;
            h = 0;
        }*/
        return new_value;
    }
};

int main()
{
    freopen("queue1.in", "r", stdin);
    freopen("queue1.out", "w", stdout);
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
