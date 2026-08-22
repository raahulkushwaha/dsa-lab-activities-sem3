#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top < MAX - 1)
    {
        stack[++top] = c;
    }
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return '\0';
}

int empty()
{
    return top == -1;
}

int isMatchingPair(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
        return 1;
    if (char1 == '{' && char2 == '}')
        return 1;
    if (char1 == '[' && char2 == ']')
        return 1;
    return 0;
}

void checkBalanced(char exp[])
{
    top = -1; // Reset stack
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (empty())
            {
                printf("Not Balanced\n");
                return;
            }
            char popped = pop();
            if (!isMatchingPair(popped, exp[i]))
            {
                printf("Not Balanced\n");
                return;
            }
        }
    }

    if (empty())
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not Balanced\n");
    }
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    char exp[MAX];
    if (scanf("%s", exp) == 1)
    {
        checkBalanced(exp);
    }

    return 0;
}
