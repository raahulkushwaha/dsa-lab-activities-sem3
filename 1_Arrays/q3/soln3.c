#include <stdio.h>

void findStockPairs()
{
    int n;
    if (scanf("%d", &n) != 1)
        return;

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int found = 0;
    int i = 0;
    while (i < n - 1)
    {
        // Find local minima (buy day)
        while ((i < n - 1) && (arr[i + 1] <= arr[i]))
        {
            i++;
        }

        if (i == n - 1)
            break;

        int buy = i++;

        // Find local maxima (sell day)
        while ((i < n) && (arr[i] >= arr[i - 1]))
        {
            i++;
        }

        int sell = i - 1;

        printf("(%d%d) ", buy, sell);
        found = 1;
    }

    if (!found)
    {
        printf("No Profit");
    }
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int t;
    if (scanf("%d", &t) == 1)
    {
        while (t--)
        {
            findStockPairs();
        }
    }

    return 0;
}
