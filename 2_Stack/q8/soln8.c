#include <stdio.h>

int arr[100000];

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxXor = 0;

    for (int i = 0; i < n; i++)
    {
        int currentXor = arr[i];
        int currentHeight = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > currentHeight)
            {
                currentXor ^= arr[j];
                currentHeight = arr[j];
            }
        }

        if (currentXor > maxXor)
        {
            maxXor = currentXor;
        }
    }

    printf("%d\n", maxXor);

    return 0;
}
