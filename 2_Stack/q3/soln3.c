#include <stdio.h>

int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n, q;
    if (scanf("%d %d", &n, &q) != 2)
        return 0;

    int arr[100000];
    int digitSum[100000];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        digitSum[i] = sumOfDigits(arr[i]);
    }

    for (int k = 0; k < q; k++)
    {
        int idx;
        scanf("%d", &idx);
        int i = idx - 1; // 1-based to 0-based index conversion
        int ans = -1;

        for (int j = i + 1; j < n; j++)
        {
            if (digitSum[i] > digitSum[j] && arr[i] < arr[j])
            {
                ans = j + 1; // Convert back to 1-based index
                break;
            }
        }

        printf("%d ", ans);
    }
    printf("\n");

    return 0;
}
