#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

int gameOver = 0, width = 30, height = 30, x, y, fruitX, fruitY, score;
int s;
int totalTail;
int tailX[100], tailY[100];

void Setup()
{
    srand(time(NULL));
    x = height/2;
    y = width/2;
    score = 0;
    Start: fruitX = 1 + rand()%width;
    fruitY = 1+ rand()%height;
    if(fruitX <= 0||fruitY <= 0||fruitX == x||fruitY == y||fruitX>height||fruitY>width)
        {
            goto Start;
        }
}

void Draw()
{
    system("cls");
    for(int i = 0;i<height;i++)
    {
        for(int j = 0; j<width; j++)
        {
            if(i == 0||j == 0||i == width-1|| j == height-1)
            {
                printf("#");
            }
            else if(i == x&&j == y)
            {
                printf("O");
            }
            else if(fruitX == i && fruitY == j)
            {
                printf("F");
            }
            else
            {
                int print = 0;
                for(int k = 0; k <totalTail; k++)
                {
                    if(tailX[k] == i&& tailY[k] == j)
                    {
                        printf("o");
                        print = 1;
                    }
                }
            if(print == 0)
            {
                printf(" ");
            }
            }
        }
        printf("\n");
    }
    printf("Score: %d", score);
}

void Input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'w':
                s = 1;
                break;
            case 's':
                s = 2;
                break;
            case 'a':
                s = 3;
                break;
            case 'd':
                s = 4;
                break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < totalTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(s)
    {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
        default:
            break;
    }
    if(s == 1||s==2)
    {
        Sleep(25);
    }
    for(int i = 0; i <totalTail; i++)
    {
        if(tailX[i] == x&&tailY[i] == y)
        {
            gameOver = 1;
        }
    }
    if(x > width-1||y>height-1||x<0||y<0)
    {
        gameOver = 1;
    }
    if(x == fruitX && y == fruitY)
    {
        score += 1;
        totalTail++;
        start2:
        fruitX = rand()%height;
        fruitY = rand()%width;
        if(fruitX <= 0||fruitY <= 0||fruitX == x||fruitY == y||fruitX>height||fruitY>width)
        {
            goto start2;
        }
    }
}

int main()
{
    Setup();
    while(gameOver != 1)
    {
        Draw();
        Logic();
        Input();
        Sleep(10);
    }
    return 0;
}
