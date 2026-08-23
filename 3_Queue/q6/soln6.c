#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front, *rear;
};

void enQueue(struct Queue *q, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    if (q->front == NULL)
    {
        q->front = temp;
    }
    else
    {
        q->rear->next = temp;
    }
    q->rear = temp;
    q->rear->next = q->front; // Circular link
}

int deQueue(struct Queue *q)
{
    if (q->front == NULL)
        return -1;

    int value;
    if (q->front == q->rear)
    {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        struct Node *temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    return value;
}

void displayQueue(struct Queue *q)
{
    if (q->front == NULL)
        return;

    struct Node *temp = q->front;
    printf("Elements in Circular Queue are: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) == 1)
    {
        struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
        q->front = q->rear = NULL;

        for (int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            enQueue(q, val);
        }

        displayQueue(q);

        int d1 = deQueue(q);
        printf("Deleted value = %d\n", d1);

        int d2 = deQueue(q);
        printf("Deleted value = %d\n", d2);

        displayQueue(q);
    }

    return 0;
}
