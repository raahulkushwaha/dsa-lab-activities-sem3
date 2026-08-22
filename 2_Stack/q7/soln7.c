#include <stdio.h>

void solve()
{
    int n;
    if (scanf("%d", &n) != 1)
        return;

    long long a[3005];
    int F[3005];
    int G[3005];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        F[i] = -1;
        G[i] = -1;
    }

    // Step 1: Find Next Greater Element index F[i]
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                F[i] = j;
                break;
            }
        }
    }

    // Step 2: Find Next Smaller Element index G[i]
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                G[i] = j;
                break;
            }
        }
    }

    // Step 3: Compute G(F(i)) and print result
    for (int i = 0; i < n; i++)
    {
        if (F[i] != -1 && G[F[i]] != -1)
        {
            printf("%lld ", a[G[F[i]]]);
        }
        else
        {
            printf("-1 ");
        }
    }
    printf("\n");
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    solve();

    return 0;
}
