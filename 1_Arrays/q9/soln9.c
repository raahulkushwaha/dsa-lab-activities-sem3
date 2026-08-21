#include <stdio.h>

void modifyMatrix(int r, int c)
{
    int arr[100][100];
    int arrTemp[100][100];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
            arrTemp[i][j] = arr[i][j];
        }
    }

    // If cell in original array is 1, set corresponding row and col to 1 in arrTemp
    for (int m = 0; m < r; m++)
    {
        for (int n = 0; n < c; n++)
        {
            if (arr[m][n] == 1)
            {
                for (int k = 0; k < c; k++)
                {
                    arrTemp[m][k] = 1;
                }
                for (int k = 0; k < r; k++)
                {
                    arrTemp[k][n] = 1;
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d", arrTemp[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int r, c;
    if (scanf("%d %d", &r, &c) == 2)
    {
        modifyMatrix(r, c);
    }

    return 0;
}
