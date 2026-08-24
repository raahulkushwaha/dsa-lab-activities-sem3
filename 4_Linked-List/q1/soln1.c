#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int n)
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
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
    return head;
}

struct node *del(struct node *head, int d)
{
    struct node *p1 = head, *p2 = NULL;

    // Remove matching nodes from head
    while (p1 != NULL && p1->data == d)
    {
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }
    head = p1;

    // Remove matching nodes after head
    while (p1 != NULL && p1->next != NULL)
    {
        if (p1->next->data == d)
        {
            p2 = p1->next;
            p1->next = p2->next;
            free(p2);
        }
        else
        {
            p1 = p1->next;
        }
    }
    return head;
}

void display(struct node *head)
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
        struct node *head = create(n);
        int d;
        scanf("%d", &d);
        head = del(head, d);
        display(head);
    }

    return 0;
}
