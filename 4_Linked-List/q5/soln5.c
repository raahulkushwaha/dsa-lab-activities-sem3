#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_Data(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_Alt(struct node **head)
{
    if (*head == NULL)
        return;

    struct node *a = *head;
    struct node *b = (*head)->next;

    while (a != NULL && b != NULL)
    {
        a->next = b->next;
        free(b);
        a = a->next;
        if (a != NULL)
        {
            b = a->next;
        }
        else
        {
            b = NULL;
        }
    }
}

void display(struct node *head)
{
    struct node *temp = head;
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

    int n;
    if (scanf("%d", &n) == 1)
    {
        struct node *head = NULL;
        for (int i = 1; i <= n; i++)
        {
            insert_Data(&head, i);
        }

        delete_Alt(&head);
        display(head);
    }

    return 0;
}
