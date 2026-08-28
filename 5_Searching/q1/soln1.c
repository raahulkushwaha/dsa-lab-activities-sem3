#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEN 50

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    char var[3][LEN];
    char inp[3][LEN];

    double M = 0.0, D = 0.0, X = 0.0;
    int hasM = 0, hasD = 0, hasX = 0;

    for (int i = 0; i < 3; i++)
    {
        if (scanf("%s %s", var[i], inp[i]) != 2)
            break;

        char v = var[i][0];
        if (inp[i][0] != '?')
        {
            double val = atof(inp[i]);
            if (v == 'M' || v == 'm')
            {
                M = val;
                hasM = 1;
            }
            else if (v == 'D' || v == 'd')
            {
                D = val;
                hasD = 1;
            }
            else if (v == 'X' || v == 'x')
            {
                X = val;
                hasX = 1;
            }
        }
    }

    if (!hasX)
    {
        X = -M / D;
        printf("x %.2f\n", fabs(X));
    }
    else if (!hasM)
    {
        M = -D * X;
        printf("m %.2f\n", M);
    }
    else if (!hasD)
    {
        D = -M / X;
        printf("d %.2f\n", D);
    }

    return 0;
}
