#include <stdio.h>
#include <stdbool.h>

int A[309][309];
bool ok[309][309][309];

int min_val(int a, int b) { return a < b ? a : b; }
int max_val(int a, int b) { return a > b ? a : b; }

void solve()
{
    int R, C, L;
    if (scanf("%d %d %d", &R, &C, &L) != 3)
        return;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (scanf("%d", &A[i][j]) != 1)
                return;
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j1 = 0; j1 < C; j1++)
        {
            int mn = A[i][j1];
            int mx = A[i][j1];
            for (int j2 = j1; j2 < C; j2++)
            {
                mn = min_val(mn, A[i][j2]);
                mx = max_val(mx, A[i][j2]);
                ok[i][j1][j2] = (mx - mn <= L);
            }
        }
    }

    int max_squares = 0;

    for (int j1 = 0; j1 < C; j1++)
    {
        for (int j2 = j1; j2 < C; j2++)
        {
            int width = j2 - j1 + 1;
            int consecutive_valid_rows = 0;

            for (int i = 0; i < R; i++)
            {
                if (ok[i][j1][j2])
                {
                    consecutive_valid_rows++;
                    int area = consecutive_valid_rows * width;
                    if (area > max_squares)
                    {
                        max_squares = area;
                    }
                }
                else
                {
                    consecutive_valid_rows = 0;
                }
            }
        }
    }

    printf("%d\n", max_squares);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int T;
    if (scanf("%d", &T) == 1)
    {
        while (T--)
        {
            solve();
        }
    }

    return 0;
}
