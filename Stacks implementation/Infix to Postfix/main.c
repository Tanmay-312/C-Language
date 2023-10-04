#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define pf printf

void push(int);
int pop();
void inf_to_post();
int priority(char);
int isEmpty();

int stack[MAX],top;
char inf[MAX], post[MAX];

void main()
{
    top = -1;
    pf("\nEnter infix expression: ");
    gets(inf);
    inf_to_post();
    pf("\nPostfix expression = %s\n\n", post);
}

void inf_to_post()
{
    int i, p=0;
    char next, sym;
    for(i=0;i<strlen(inf);i++)
    {
        sym = inf[i];
        switch(sym)
        {
            case '(' :
                   push(sym);
                   break;
            case ')' :
                    while((next=pop())!= '(')
                            post[p++]=next;
                    break;
            case '+' :
            case '-' :
            case '*' :
            case '/' :
                    while(!isEmpty() && priority(sym)<=priority(stack[top]))
                        post[p++]=pop();
                    push(sym);
                    break;
            default :
                post[p++]=sym;
        }
    }
    while(!isEmpty())
        post[p++] = pop();
    post[p] = '\0';
}

int priority(char s)
{
    switch(s)
    {
        case '(' :
                return 0;
        case '+' :
        case '-' :
                return 1;
        case '*' :
        case '/' :
                return 2;
        default :
                return 0;
    }
}

void push(int s)
{
    if(top==MAX-1)
    {
        pf("\nStack overflow\n\n");
        exit(1);
    }
    stack[++top] = s;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int pop()
{
    if(isEmpty())
    {
        pf("\nStack underflow\n\n");
        exit(1);
    }
    return stack[top--];
}
