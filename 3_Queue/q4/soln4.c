#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d)
{
    struct node *new_n = (struct node *)malloc(sizeof(struct node));
    new_n->data = d;
    new_n->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = new_n;
    }
    else
    {
        rear->next = new_n;
        rear = new_n;
    }
}

void dequeue()
{
    if (front == NULL)
        return;
    struct node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void print()
{
    if (front == NULL)
    {
        printf("No data in the queue.\n");
        return;
    }
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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

        print();
        dequeue();
        print();
    }

    return 0;
}
