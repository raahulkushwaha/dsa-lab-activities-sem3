#include <stdio.h>
#include <string.h>

#define MAXN 200005

char s[MAXN];
int n, m;

int getLongest()
{
    int max_len = 1;
    int current_len = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            current_len++;
        }
        else
        {
            if (current_len > max_len)
            {
                max_len = current_len;
            }
            current_len = 1;
        }
    }
    if (current_len > max_len)
    {
        max_len = current_len;
    }
    return max_len;
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    if (scanf("%s", s) != 1)
        return 0;
    n = strlen(s);

    if (scanf("%d", &m) != 1)
        return 0;

    for (int i = 0; i < m; i++)
    {
        int pos;
        scanf("%d", &pos);
        pos--; // 1-based to 0-based index

        // Invert bit
        s[pos] = (s[pos] == '0') ? '1' : '0';

        printf("%d ", getLongest());
    }
    printf("\n");

    return 0;
}
