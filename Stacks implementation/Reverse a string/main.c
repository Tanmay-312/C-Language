#include <stdio.h>
#include <string.h>
#define MAX 100

int top=-1;
int item;

char stack[MAX];
void push(char item);
char pop(void);
int isEmpty(void);

int main()
{
    char str[MAX];
    int i;
    printf("Input a string: ");
    gets(str);

    for(i=0;i<strlen(str);i++)
        pushChar(str[i]);

    for(i=0;i<strlen(str);i++)
        str[i]=popChar();

    printf("Reversed String is: %s\n",str);
    return 0;
}


void push(char item)
{
    if(top==MAX-1)
    {
        printf("\nStack is FULL !!!\n");
        return;
    }

    top++;
    stack[top]=item;
}


 char pop()
{
    if(isEmpty())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }

    item = stack[top];
    top--;
    return item;
}


int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
