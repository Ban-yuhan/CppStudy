#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS


int main(void)
{

}

void BingoGame()
{
    char displayArray[3][3] = { {'O','O','O'}, {'O','O','O'},{'O','O','O'} };
    int x, int y;
    int playerNumber = 1;

    bool winCheck[2] = { false, false };

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            printf("%c ", displayArray[y][x]);
        }
        printf("\n");
    }

    while (true)
    {
        printf("Input Player%d (x,y):", playerNumber);
        scanf_s("%d,%d", &x, &y);

        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                printf("%c ", displayArray[y][x]);
            }
            printf("\n");
        }

        //데이터의 승리조건을 체크하여 승리조건이 맞는지 확인한다.

        if (winCheck[0] || winCheck[1])
            break;
    }

    printf("Player %d Win!\n", playerNumber);
}