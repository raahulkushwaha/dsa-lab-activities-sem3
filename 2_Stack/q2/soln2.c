#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct mystack
{
    Node *top;
} mystack;

void push(int data, mystack *ms)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = ms->top;
    ms->top = newNode;
}

int pop(mystack *ms)
{
    if (ms->top == NULL)
        return -1;
    Node *temp = ms->top;
    int val = temp->data;
    ms->top = ms->top->next;
    free(temp);
    return val;
}

void merge(mystack *ms1, mystack *ms2)
{
    if (ms1->top == NULL)
    {
        ms1->top = ms2->top;
        return;
    }
    Node *curr = ms1->top;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = ms2->top;
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    mystack ms1 = {NULL};
    mystack ms2 = {NULL};

    int val;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &val) == 1)
        {
            push(val, &ms1);
        }
    }

    // Reads up to n elements for stack 2, stopping if line ends
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &val) == 1)
        {
            push(val, &ms2);
        }
        else
        {
            break;
        }
    }

    // Top before pop operation
    if (ms1.top != NULL)
    {
        printf("Top element: %d\n", ms1.top->data);
    }

    // Perform m pops
    for (int i = 0; i < m; i++)
    {
        pop(&ms1);
    }

    // Merge and display final stack elements
    merge(&ms1, &ms2);

    Node *curr = ms1.top;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}
