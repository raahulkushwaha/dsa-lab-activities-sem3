#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *reverseList(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void foldList(struct node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    // Step 1: Find middle using slow and fast pointers
    struct node *slow = *head, *fast = *head, *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Split into two halves
    if (prev != NULL)
    {
        prev->next = NULL;
    }

    // Step 2: Reverse second half
    struct node *secondHalf = reverseList(slow);
    struct node *firstHalf = *head;

    // Step 3: Alternate merge
    struct node *dummy = (struct node *)malloc(sizeof(struct node));
    struct node *curr = dummy;

    while (firstHalf != NULL || secondHalf != NULL)
    {
        if (firstHalf != NULL)
        {
            curr->next = firstHalf;
            curr = curr->next;
            firstHalf = firstHalf->next;
        }
        if (secondHalf != NULL)
        {
            curr->next = secondHalf;
            curr = curr->next;
            secondHalf = secondHalf->next;
        }
    }

    *head = dummy->next;
    free(dummy);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) == 1)
    {
        struct node *head = NULL;
        for (int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            create(&head, val);
        }

        printf("Link list data:");
        print(head);

        foldList(&head);

        printf("Link list data after fold:");
        print(head);
    }

    return 0;
}
