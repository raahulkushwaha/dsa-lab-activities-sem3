#include <stdio.h>
#include <string.h>

void convertToMartian(int n)
{
    char buf[100];
    int i = 0;

    // Martian conversion logic mapping values to specific symbol representations
    while (n >= 1000)
    {
        buf[i++] = 'R';
        n -= 1000;
    }
    while (n >= 500)
    {
        buf[i++] = 'G';
        n -= 500;
    }
    while (n >= 400)
    {
        buf[i++] = 'B';
        buf[i++] = 'G';
        n -= 400;
    }
    while (n >= 100)
    {
        buf[i++] = 'B';
        n -= 100;
    }
    while (n >= 90)
    {
        buf[i++] = 'P';
        buf[i++] = 'B';
        n -= 90;
    }
    while (n >= 50)
    {
        buf[i++] = 'P';
        n -= 50;
    }
    while (n >= 40)
    {
        buf[i++] = 'Z';
        buf[i++] = 'P';
        n -= 40;
    }
    while (n >= 10)
    {
        buf[i++] = 'Z';
        n -= 10;
    }
    while (n >= 9)
    {
        buf[i++] = 'W';
        buf[i++] = 'Z';
        n -= 9;
    }
    while (n >= 5)
    {
        buf[i++] = 'W';
        n -= 5;
    }
    while (n >= 4)
    {
        buf[i++] = 'B';
        buf[i++] = 'W';
        n -= 4;
    }
    while (n >= 1)
    {
        buf[i++] = 'B';
        n -= 1;
    }

    buf[i] = '\0';
    printf("%s\n", buf);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int num;
    while (scanf("%d", &num) != EOF)
    {
        convertToMartian(num);
    }

    return 0;
}
