#include <stdio.h>

void playGame()
{
    int n;
    if (scanf("%d", &n) != 1)
        return;

    int a[100000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        if (left == right)
        {
            // Both are pointing to the exact same element remaining
            printf("0");
            break;
        }

        if (a[left] > a[right])
        {
            printf("1");
            right--; // B removes the picked number
        }
        else if (a[left] < a[right])
        {
            printf("2");
            left++; // A removes the picked number
        }
        else
        {
            printf("0");
            left++;
            right--; // Both remove their picked numbers
        }
    }
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    playGame();

    return 0;
}
