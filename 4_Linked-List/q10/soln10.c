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

void deleteFront(int d)
{
    for (int i = 0; i < d && head != NULL; i++)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
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
        int d;
        scanf("%d", &d);
        deleteFront(d);
        display();
    }

    return 0;
}
