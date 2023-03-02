#include <stdio.h>
#define n 3
#include <stdbool.h>
#include <stdlib.h>
int timer = 2;
void gameend(bool gameover, int turn)
{
    if (gameover == true)
    {
        if (turn == 0)
        {
            printf("o win! game over");
        }
        else
            printf("x win! game over");
        exit(0);
    }
}
bool comp(int a, int b, int c)
{

    if (a == b && b == c)
    {
        return true;
    }
    else
        return false;
}
void printarray(char array[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("|%c", array[i][j]);
        }
        printf("| \n");
    }
}
int update(int r, int c, char array[n][n], int A[n][n])
{
    if (array[r][c] == '-')
    {
        if (timer % 2 == 0)
        {
            array[r][c] = 'x';
            A[r][c] = 1;
        }
        else
        {
            array[r][c] = 'o';
            A[r][c] = 0;
        }
        printarray(array);
        return A[r][c];
    }
    else
    {
        timer = timer - 1;
        printf("enter different value");
    }
    return 0;
}
int main()
{
    int buffer = 1, choice, arr[n][n] = {2, 3, 4, 5, 6, 7, 8, 9, 10}, turn;
    char array[n][n] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    bool result, gameover = false;
    printarray(array);
    while (gameover != true)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            turn = update(0, choice - 1, array, arr);
            break;
        case 2:
            turn = update(0, choice - 1, array, arr);
            break;
        case 3:
            turn = update(0, choice - 1, array, arr);
            break;
        case 4:
            turn = update(1, choice - 4, array, arr);
            break;
        case 5:
            turn = update(1, choice - 4, array, arr);
            break;
        case 6:
            turn = update(1, choice - 4, array, arr);
            break;
        case 7:
            turn = update(2, choice - 7, array, arr);
            break;
        case 8:
            turn = update(2, choice - 7, array, arr);
            break;
        case 9:
            turn = update(2, choice - 7, array, arr);
            break;
        default:
            printf("invalid input");
            break;
        }
        printf("\n");
        timer++;
        buffer = buffer + 1;
        gameover = comp(arr[0][0], arr[0][1], arr[0][2]);
        gameend(gameover, turn);
        gameover = comp(arr[1][0], arr[1][1], arr[1][2]);
        gameend(gameover, turn);
        gameover = comp(arr[2][0], arr[2][1], arr[2][2]);
        gameend(gameover, turn);
        gameover = comp(arr[0][0], arr[1][1], arr[2][2]);
        gameend(gameover, turn);
        gameover = comp(arr[2][0], arr[1][1], arr[0][2]);
        gameend(gameover, turn);
        gameover = comp(arr[2][0], arr[2][1], arr[2][2]);
        gameend(gameover, turn);
        gameover = comp(arr[0][0], arr[1][0], arr[2][0]);
        gameend(gameover, turn);
        gameover = comp(arr[0][1], arr[1][1], arr[2][1]);
        gameend(gameover, turn);
        gameover = comp(arr[0][2], arr[1][2], arr[2][2]);
        gameend(gameover, turn);
    }
    if (buffer == 10)
    {
        gameover = true;
    }
    printf("game over");
}
