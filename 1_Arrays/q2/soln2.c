#include <stdio.h>

void generateMatrix(int p, int q)
{
    char matrix[1000][1000];
    int top = 0, bottom = p - 1;
    int left = 0, right = q - 1;
    char currentChar = 'Y';

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            matrix[top][i] = currentChar;
            matrix[bottom][i] = currentChar;
        }
        for (int i = top; i <= bottom; i++)
        {
            matrix[i][left] = currentChar;
            matrix[i][right] = currentChar;
        }

        top++;
        bottom--;
        left++;
        right--;

        currentChar = (currentChar == 'Y') ? 'O' : 'Y';
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int p, q;
    if (scanf("%d %d", &p, &q) == 2)
    {
        generateMatrix(p, q);
    }

    return 0;
}
