#include <stdio.h>
#include <stdlib.h>

struct n
{
    int data;
    struct n *next;
};

struct n *head = NULL;

void insert(int data)
{
    struct n *newNode = (struct n *)malloc(sizeof(struct n));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct n *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void display(struct n *h)
{
    if (h == NULL)
        return;
    struct n *temp = h;
    printf("[h] => ");
    do
    {
        printf("%d => ", temp->data);
        temp = temp->next;
    } while (temp != h);
    printf("[h]\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            insert(i);
        }

        printf("Complete linked_list:\n");
        display(head);

        // Separate odd and even nodes into circular lists
        struct n *oddHead = NULL, *oddTail = NULL;
        struct n *evenHead = NULL, *evenTail = NULL;

        struct n *curr = head;
        int count = 1;

        do
        {
            struct n *newNode = (struct n *)malloc(sizeof(struct n));
            newNode->data = curr->data;
            newNode->next = NULL;

            if (count % 2 != 0)
            {
                if (oddHead == NULL)
                {
                    oddHead = oddTail = newNode;
                    oddTail->next = oddHead;
                }
                else
                {
                    oddTail->next = newNode;
                    oddTail = newNode;
                    oddTail->next = oddHead;
                }
            }
            else
            {
                if (evenHead == NULL)
                {
                    evenHead = evenTail = newNode;
                    evenTail->next = evenHead;
                }
                else
                {
                    evenTail->next = newNode;
                    evenTail = newNode;
                    evenTail->next = evenHead;
                }
            }
            curr = curr->next;
            count++;
        } while (curr != head);

        printf("Odd:\n");
        display(oddHead);

        printf("Even:\n");
        display(evenHead);
    }

    return 0;
}
