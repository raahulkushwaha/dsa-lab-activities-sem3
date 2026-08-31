#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int hexDigitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 16);
        n /= 16;
    }
    return sum;
}

int search(int a, int b)
{
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        int f_x = hexDigitSum(i);
        if (gcd(i, f_x) > 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int t;
    if (scanf("%d", &t) == 1)
    {
        while (t--)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", search(l, r));
        }
    }

    return 0;
}
