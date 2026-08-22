#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

char stack[MAX][MAX];
int top = -1;

void push(char *str)
{
    if (top < MAX - 1)
    {
        strcpy(stack[++top], str);
    }
}

void pop(char *str)
{
    if (top >= 0)
    {
        strcpy(str, stack[top--]);
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postToPre(char *post_exp)
{
    top = -1; // Reset stack
    int len = strlen(post_exp);

    for (int i = 0; i < len; i++)
    {
        if (isalnum(post_exp[i]))
        {
            char op[2] = {post_exp[i], '\0'};
            push(op);
        }
        else if (isOperator(post_exp[i]))
        {
            char op1[MAX], op2[MAX];
            pop(op2); // First pop gets second operand
            pop(op1); // Second pop gets first operand

            // Form: Operator + Operand1 + Operand2
            char temp[MAX];
            temp[0] = post_exp[i];
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);

            push(temp);
        }
    }

    printf("%s\n", stack[top]);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    char post_exp[MAX];
    if (scanf("%s", post_exp) == 1)
    {
        postToPre(post_exp);
    }

    return 0;
}
