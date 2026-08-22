#include <stdio.h>

#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x)
{
    if (top1 < top2 - 1)
    {
        top1++;
        arr[top1] = x;
    }
}

void push2(int x)
{
    if (top1 < top2 - 1)
    {
        top2--;
        arr[top2] = x;
    }
}

int pop1()
{
    if (top1 >= 0)
    {
        int x = arr[top1];
        top1--;
        return x;
    }
    return -1;
}

int pop2()
{
    if (top2 < MAX)
    {
        int x = arr[top2];
        top2++;
        return x;
    }
    return -1;
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int val;
    int count = 0;

    // Alternately push elements to stack1 and stack2
    while (count < 5 && scanf("%d", &val) == 1)
    {
        if (count % 2 == 0)
        {
            push1(val);
        }
        else
        {
            push2(val);
        }
        count++;
    }

    // Perform pops and output results
    while (top1 >= 0 || top2 < MAX)
    {
        if (top1 >= 0)
        {
            printf("Popped element from stack1 is:%d\n", pop1());
        }
        if (top2 < MAX)
        {
            printf("Popped element from stack2 is:%d\n", pop2());
        }
    }

    return 0;
}
