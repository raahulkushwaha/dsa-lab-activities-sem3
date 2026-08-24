#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void sortedInsert(struct Node **head_ref, struct Node *new_node)
{
    struct Node *current = *head_ref;

    // Case 1: Empty list
    if (current == NULL)
    {
        new_node->next = new_node;
        *head_ref = new_node;
    }
    // Case 2: Insert before head
    else if (current->data >= new_node->data)
    {
        while (current->next != *head_ref)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    // Case 3: Insert after head in correct sorted position
    else
    {
        while (current->next != *head_ref && current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
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
            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = val;
            new_node->next = NULL;
            sortedInsert(&head, new_node);
        }

        printList(head);
    }

    return 0;
}
