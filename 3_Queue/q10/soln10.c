#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = data;
}

void reverse()
{
    int i = front;
    int j = rear;
    while (i < j)
    {
        int temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
        i++;
        j--;
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

    int size;
    if (scanf("%d", &size) == 1)
    {
        for (int i = 0; i < size; i++)
        {
            int val;
            scanf("%d", &val);
            enqueue(val);
        }

        printf("Queue: ");
        display();

        reverse();

        printf("Reversed Queue: ");
        display();
    }

    return 0;
}
