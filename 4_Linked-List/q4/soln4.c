#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void create(int n)
{
    struct node *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (start == NULL)
        {
            start = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void insertBefore(int p, int x)
{
    if (start == NULL)
        return;

    // If target node P is the first node
    if (start->data == p)
    {
        struct node *p1 = (struct node *)malloc(sizeof(struct node));
        p1->data = x;
        p1->next = start;
        start = p1;
        return;
    }

    struct node *p2 = start;
    int found = 0;

    while (p2->next != NULL)
    {
        if (p2->next->data == p)
        {
            found = 1;
            break;
        }
        p2 = p2->next;
    }

    if (found)
    {
        struct node *p1 = (struct node *)malloc(sizeof(struct node));
        p1->data = x;
        p1->next = p2->next;
        p2->next = p1;
    }
    else
    {
        printf("Node not found!\n");
    }
}

void display()
{
    printf("Linked List:->");
    struct node *temp = start;
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
        int p, x;
        scanf("%d %d", &p, &x);
        insertBefore(p, x);
        display();
    }

    return 0;
}
