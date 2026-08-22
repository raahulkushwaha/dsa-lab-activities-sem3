#include <stdio.h>

void calculateSpan(int price[], int n, int S[])
{
    int st[1000];
    int top = -1;

    // Span value for first day is always 1
    S[0] = 1;
    st[++top] = 0;

    for (int i = 1; i < n; i++)
    {
        // Pop elements from stack while stack is not empty and top element is smaller than or equal to price[i]
        while (top >= 0 && price[st[top]] <= price[i])
        {
            top--;
        }

        // If stack becomes empty, then price[i] is greater than all elements on left
        S[i] = (top == -1) ? (i + 1) : (i - st[top]);

        // Push this element to stack
        st[++top] = i;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) == 1)
    {
        int price[1000];
        int S[1000];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &price[i]);
        }

        calculateSpan(price, n, S);
        printArray(S, n);
    }

    return 0;
}
