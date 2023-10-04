#include <stdio.h>
#include <stdlib.h>
#define SIZE 9
#define get_low_bit(x) ((~x&(x-1))+1)
struct
{
    int left;
    char num;
    char try;
}board[SIZE][SIZE];

int bit2num(int bit)
{
    switch(bit)
    {
        case 1: case 2:
        return bit;
        case 4:
        return 3;
        case 8:
        return 4;
        case 16:
        return 5;
        case 32:
        return 6;
        case 64:
        return 7;
        case 128:
        return 8;
        case 256:
        return 9;
    }
}

void printf_res()
{
    int i, j, k;
    for(i=0; i<SIZE; i++)
    {
        if(i%3==0)
        {
            for(j=0; j<SIZE*2+4; j++)
            putchar('-');
            putchar('\n');
        }
        for(j=0; j<SIZE; j++)
        {
            if(j%3==0)
            putchar('|');
            if(board[i][j].num > 0)
            printf("%2d", board[i][j].num);
            else
            printf("%2d", board[i][j].try);
        }
        printf("|\n");
    }
    for(i=0; i<SIZE*2+4; i++)
    putchar('-');
    putchar('\n');
}

void sub(int i, int j, int bit)
{
    int k, m;
    for(k=0; k<SIZE; k++)
    {
        board[k][j].left &= ~bit;
        board[i][k].left &= ~bit;
    }
    for(k=i/3*3; k<(i/3+1)*3; k++)
    for(m=j/3*3; m<(j/3+1)*3; m++)
    board[k][m].left &= ~bit;
}

void init()
{
    int i, j;
    for(i=0; i<SIZE; i++)
    for(j=0; j<SIZE; j++)
    if(board[i][j].num > 0)
    sub(i, j, 1<<(board[i][j].num-1));
    else if(board[i][j].try > 0)
    sub(i, j, 1<<(board[i][j].try-1));
}

void add(int i, int j, int bit)
{
    int k, m;
    for(k=0; k<SIZE; k++)
    {
        board[k][j].left |= bit;
        board[i][k].left |= bit;
    }
    for(k=i/3*3; k<(i/3+1)*3; k++)
    for(m=j/3*3; m<(j/3+1)*3; m++)
    board[k][m].left |= bit;
}

void solve(int pos)
{
    int i=pos/SIZE;
    int j=pos%SIZE;
    int bit, left;
    if(pos == SIZE*SIZE)
    {
        printf_res();
        exit(0);
    }
    if(board[i][j].num > 0)
    solve(pos+1);
    else for(left=board[i][j].left; left; left&=(left-1))
    {
        bit = get_low_bit(left);
        sub(i, j, bit);
        board[i][j].try = bit2num(bit);
        solve(pos+1);
        add(i, j, bit);
        board[i][j].try=0;
        init();
    }
}

int main()
{
    int i, j, c;
    printf("Use '0' for blank space !\n");
    for(i=0; i<SIZE; i++)
    for(j=0; j<SIZE; j++)
    {
        while((c=getchar())<'0' || c>'9') ;
        board[i][j].num = c-'0';
        board[i][j].try = 0;
        board[i][j].left = 0x0001FF;
    }
    init();
    solve(0);
    return 0;
}
