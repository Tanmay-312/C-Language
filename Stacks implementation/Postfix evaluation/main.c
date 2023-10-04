#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

void push(int);
int pop();
int eval();

char post[MAX];
int stack[MAX], top;

void main()
{
    int value;
    top = -1;
    printf("\nEnter postfix expression: ");
    gets(post);
    value = eval();
    printf("\nValue of expression = %d\n\n", value);
}

void push(int s)
{
    if(top==MAX-1)
    {
        printf("\nStack overflow\n\n");
        exit(1);
    }
    stack[++top] = s;
}

int pop()
{
    if(top==-1)
    {
        printf("\nStack underflow\n\n");
        exit(1);
    }
    return (stack[top--]);
}

int eval()
{
    int a,b,value,r,i;
    for(i=0;i<strlen(post);i++)
    {
        if(post[i]>='0' && post[i]<='9')
            push(post[i]-'0');
        else
        {
            b = pop();
            a = pop();
            switch(post[i])
            {
                case '+':
                        value = a+b;
                        break;
                case '-':
                        value = a-b;
                        break;
                case '*':
                        value = a*b;
                        break;
                case '/':
                        value = a/b;
                        break;
            }
            push(value);
        }
    }
    r = pop();
    return r;
}
