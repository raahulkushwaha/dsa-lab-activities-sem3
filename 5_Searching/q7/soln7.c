#include <stdio.h>

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int n;
    if (scanf("%d", &n) == 1)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            double width, height;
            scanf("%lf %lf", &width, &height);

            double ratio1 = width / height;
            double ratio2 = height / width;

            if (ratio1 >= 1.6 && ratio1 <= 1.7)
            {
                count++;
            }
            else if (ratio2 >= 1.6 && ratio2 <= 1.7)
            {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
