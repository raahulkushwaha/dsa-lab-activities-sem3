#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;

    if (f == NULL && r == NULL)
    {
        f = r = n;
        r->next = f;
    }
    else
    {
        r->next = n;
        r = n;
        r->next = f;
    }
}

void display()
{
    if (f == NULL)
        return;

    struct node *t = f;
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != f);
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int size;
    if (scanf("%d", &size) == 1)
    {
        for (int i = 0; i < size; i++)
        {
            int val;
            scanf("%d", &val);
            enqueue(val);
        }

        display();
    }

    return 0;
}
