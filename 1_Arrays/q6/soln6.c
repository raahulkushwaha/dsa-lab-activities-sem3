#include <stdio.h>
#include <string.h>

#define MAX 10
#define LEN 50

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int budget, items;
    if (scanf("%d %d", &budget, &items) != 2)
        return 0;

    char name[MAX][LEN];
    int price[MAX];
    int afford[MAX] = {0};

    for (int i = 0; i < items; i++)
    {
        scanf("%s %d", name[i], &price[i]);
    }

    int remaining = budget;
    int bought_any = 0;

    for (int i = 0; i < items; i++)
    {
        if (remaining >= price[i])
        {
            afford[i] = 1;
            remaining -= price[i];
            bought_any = 1;
            printf("I can afford %s\n", name[i]);
        }
        else
        {
            printf("I can't afford %s\n", name[i]);
        }
    }

    if (!bought_any)
    {
        printf("I need more Dollar!\n");
    }
    else
    {
        printf("%d\n", remaining);
    }

    return 0;
}
