#include <stdio.h>

int queue[100];
int front = 0;
int rear = -1;

void enqueue(int data)
{
    queue[++rear] = data;
}

void dequeue()
{
    if (front <= rear)
    {
        front++;
    }
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int data;
            scanf("%d", &data);
            enqueue(data);
        }

        printf("Dequeuing elements:\n");
        while (front < rear)
        {
            dequeue();
            display();
        }
    }

    return 0;
}
