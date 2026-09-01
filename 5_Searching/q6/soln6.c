#include <stdio.h>
#include <limits.h>

void thirdLargest(int arr[], int arr_size)
{
    if (arr_size < 3)
    {
        printf("Invalid Input\n");
        return;
    }

    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second)
        {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third)
        {
            third = arr[i];
        }
    }

    printf("The third Largest element is %d\n", third);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) == 1)
    {
        int arr[100];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        thirdLargest(arr, n);
    }

    return 0;
}
