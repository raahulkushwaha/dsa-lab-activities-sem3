#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void disp()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = data;

    printf("Enqueuing %d\n", data);
    disp();
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int size;
    if (scanf("%d", &size) == 1)
    {
        for (int i = 0; i < size; i++)
        {
            int data;
            scanf("%d", &data);
            enqueue(data);
        }
    }

    return 0;
}
