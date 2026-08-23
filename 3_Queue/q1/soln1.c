#include <stdio.h>

void solve()
{
    int n;
    if (scanf("%d", &n) != 1)
        return;

    long long a[100005];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    long long biggest = -1, big = -1, medium = -1;

    for (int i = 0; i < n; i++)
    {
        long long val = a[i];

        // Maintain top 3 largest elements
        if (val > biggest)
        {
            medium = big;
            big = biggest;
            biggest = val;
        }
        else if (val > big)
        {
            medium = big;
            big = val;
        }
        else if (val > medium)
        {
            medium = val;
        }

        if (i < 2)
        {
            printf("-1\n");
        }
        else
        {
            long long ans = biggest * big * medium;
            printf("%lld\n", ans);
        }
    }
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    solve();

    return 0;
}
