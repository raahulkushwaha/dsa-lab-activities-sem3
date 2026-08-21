#include <stdio.h>

#define MAXN 100

void sol()
{
    int n;
    if (scanf("%d", &n) != 1)
        return;

    int s[MAXN];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    // Sort the animal sizes in ascending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] > s[j])
            {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Assign treat levels based on distinct rank sizes
    int treats[MAXN];
    treats[0] = 1;
    int total_treats = treats[0];

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            treats[i] = treats[i - 1];
        }
        else
        {
            treats[i] = treats[i - 1] + 1;
        }
        total_treats += treats[i];
    }

    printf("%d\n", total_treats);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int t;
    if (scanf("%d", &t) == 1)
    {
        while (t--)
        {
            sol();
        }
    }

    return 0;
}
