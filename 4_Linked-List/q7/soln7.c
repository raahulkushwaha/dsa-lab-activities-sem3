#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n)
{
    struct node *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void del(int val)
{
    if (head == NULL)
        return;

    // Check if target value exists and find its node pointer
    struct node *target = head;
    while (target != NULL && target->data != val)
    {
        target = target->next;
    }

    // If target value doesn't exist or is the very first node, it's invalid
    if (target == NULL || target == head)
    {
        printf("Invalid Node! ");
        return;
    }

    // Free all nodes preceding the target node
    struct node *curr = head;
    while (curr != target)
    {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    // Update head to target node
    head = target;
}

void display()
{
    printf("Linked List:->");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf("->");
        }
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
        create(n);
        int val;
        scanf("%d", &val);
        del(val);
        display();
    }

    return 0;
}
