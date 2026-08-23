#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int pageNumber;
    struct QNode *prev, *next;
} QNode;

typedef struct Queue
{
    int numberOfFrames;
    int count;
    QNode *front, *rear;
} Queue;

QNode *newQNode(unsigned pageNumber)
{
    QNode *temp = (QNode *)malloc(sizeof(QNode));
    temp->pageNumber = pageNumber;
    temp->prev = temp->next = NULL;
    return temp;
}

Queue *createQueue(int numberOfFrames)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->numberOfFrames = numberOfFrames;
    queue->count = 0;
    queue->front = queue->rear = NULL;
    return queue;
}

void referencePage(Queue *queue, int pageNumber)
{
    QNode *cur = queue->front;
    QNode *found = NULL;

    // Check if page already exists in cache
    while (cur != NULL)
    {
        if (cur->pageNumber == pageNumber)
        {
            found = cur;
            break;
        }
        cur = cur->next;
    }

    if (found != NULL)
    {
        // Move existing node to front (most recently used)
        if (found != queue->front)
        {
            if (found == queue->rear)
            {
                queue->rear = found->prev;
                queue->rear->next = NULL;
            }
            else
            {
                found->prev->next = found->next;
                found->next->prev = found->prev;
            }
            found->next = queue->front;
            found->prev = NULL;
            queue->front->prev = found;
            queue->front = found;
        }
    }
    else
    {
        // Create new node
        QNode *temp = newQNode(pageNumber);
        if (queue->count == queue->numberOfFrames)
        {
            // Remove least recently used page from rear
            QNode *last = queue->rear;
            queue->rear = queue->rear->prev;
            if (queue->rear)
            {
                queue->rear->next = NULL;
            }
            else
            {
                queue->front = NULL;
            }
            free(last);
            queue->count--;
        }

        temp->next = queue->front;
        if (queue->front)
        {
            queue->front->prev = temp;
        }
        queue->front = temp;
        if (queue->rear == NULL)
        {
            queue->rear = queue->front;
        }
        queue->count++;
    }
}

void displayCache(Queue *queue)
{
    QNode *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d", temp->pageNumber);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n, m;
    if (scanf("%d %d", &n, &m) == 2)
    {
        Queue *q = createQueue(m);
        for (int i = 0; i < n; i++)
        {
            int page;
            scanf("%d", &page);
            referencePage(q, page);
        }
        displayCache(q);
    }

    return 0;
}
