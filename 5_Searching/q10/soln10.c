#include <stdio.h>
#include <math.h>

long long getCount(long long val)
{
    if (val <= 0)
        return 0;
    long long sq = (long long)sqrt(val);
    long long half = (val + 1) / 2;
    return val * sq + half;
}

long long findValueAtIndex(long long idx)
{
    long long low = 1, high = 1000000, ans = 1;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (getCount(mid) >= idx)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    long long L, R;
    if (scanf("%lld %lld", &L, &R) != 2)
        return;

    long long ans1 = findValueAtIndex(L);
    long long ans2 = findValueAtIndex(R);

    long long distinct_count = ans2 - ans1 + 1;
    printf("%lld\n", distinct_count);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int Q;
    if (scanf("%d", &Q) == 1)
    {
        while (Q--)
        {
            solve();
        }
    }

    return 0;
}
