#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int gameover, score;
int x, y, fruitX, fruitY, flag;
int tailX[100], tailY[100];
int nTail;

void setup()
{
    gameover = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    flag = 0;
}

void draw()
{
    system("cls");
    int i, j;
    for (i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else
            {
                int isprint = 0;
                int k;
                for (k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        printf("o");
                        isprint = 1;
                    }
                }
                if (!isprint)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score = %d\n", score);
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            flag = 1;
            break;
        case 'd':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 's':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    int i;
    for (i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag)
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

    if (x >= WIDTH)
        x = 0;
    else if (x < 0)
        x = WIDTH - 1;
    if (y >= HEIGHT)
        y = 0;
    else if (y < 0)
        y = HEIGHT - 1;

    for (i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

int main()
{
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
        Sleep(100);
    }
    return 0;
}

