#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertStart(struct Node **head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

void printForward(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) == 1)
    {
        struct Node *head = NULL;
        for (int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            insertStart(&head, val);
        }

        printForward(head);
        printBackward(head);
    }

    return 0;
}
