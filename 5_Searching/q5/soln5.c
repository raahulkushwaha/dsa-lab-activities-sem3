#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void solve(int k)
{
    int N;
    if (scanf("%d", &N) != 1)
        return;

    char s[105];
    scanf("%s", s);

    int b[105];
    for (int i = 1; i <= N; i++)
    {
        b[i] = s[i - 1] - '0';
    }

    int pref[105] = {0};
    for (int i = 1; i <= N; i++)
    {
        pref[i] = pref[i - 1] + b[i];
    }

    int len = (N + 1) / 2;
    int max_beauty = 0;

    for (int i = 1; i + len - 1 <= N; i++)
    {
        int sum = pref[i + len - 1] - pref[i - 1];
        max_beauty = max(max_beauty, sum);
    }

    printf("%d\n", max_beauty);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int T;
    if (scanf("%d", &T) == 1)
    {
        for (int k = 1; k <= T; ++k)
        {
            solve(k);
        }
    }

    return 0;
}
