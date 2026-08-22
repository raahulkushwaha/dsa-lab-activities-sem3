#include <stdio.h>

#define MAX 1000

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = val;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    int val = queue[front++];
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
    return val;
}

int size()
{
    if (front == -1)
        return 0;
    return rear - front + 1;
}

// Push to stack using a single queue
void push(int val)
{
    int s = size();
    enqueue(val);
    for (int i = 0; i < s; i++)
    {
        enqueue(dequeue());
    }
}

// Pop from stack
int pop()
{
    return dequeue();
}

int top()
{
    if (front == -1)
        return -1;
    return queue[front];
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    int val;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &val) == 1)
        {
            push(val);
        }
    }

    printf("top of element %d\n", top());

    for (int i = 0; i < m; i++)
    {
        pop();
    }

    printf("top of element %d\n", top());

    return 0;
}
