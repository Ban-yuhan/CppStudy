#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void BingoGame();

int main(void)
{
    BingoGame();
}

void BingoGame()
{
    char displayArray[3][3] = { {'O','O','O'}, {'O','O','O'},{'O','O','O'} };
    int x;
    int y;
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
    printf("\n");

    while (true)
    {
        printf("Input Player%d (x,y):", playerNumber);
        scanf_s("%d,%d", &x, &y);

		if (playerNumber == 1 && displayArray[y][x] == 'O')
		{
            displayArray[y][x] = 'X'; //배열에서는 y가 먼저
            playerNumber = 2;

            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    printf("%c ", displayArray[y][x]);

                }
                printf("\n");
            }
            printf("\n");
		}

		else if (playerNumber == 2 && displayArray[y][x] == 'O')
		{
			displayArray[y][x] = '@';
            playerNumber = 1;

            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    printf("%c ", displayArray[y][x]);

                }
                printf("\n");
            }
            printf("\n");
		}

        else if( x < 3 && y < 3 && displayArray[y][x] != 'O')
        {
			printf("이미 선택된 칸입니다. 다시 선택해주세요.\n");
        }
        
        else if(x > 2 || y > 2)
        {
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
              

        //데이터의 승리조건을 체크하여 승리조건이 맞는지 확인한다.
        int i = 0;

		//player1 승리조건 체크

        //가로방향 체크
        for (i = 0;i <= 2;++i)
        {
            if (displayArray[i][0] == 'X' && displayArray[i][1] == 'X' && displayArray[i][2] == 'X')
            {
                winCheck[0] = true;
            }
        }

		//세로방향 체크
        for (i = 0; i <= 2; ++i)
        {
            if (displayArray[0][i] == 'X' && displayArray[1][i] == 'X' && displayArray[2][i] == 'X')
            {
                winCheck[0] = true;
            }
        }
      
		//대각선방향 체크
        if (displayArray[0][0] == 'X' && displayArray[1][1] == 'X' && displayArray[2][2] == 'X')
        {
            winCheck[0] = true;
        }

        if (displayArray[0][2] == 'X' && displayArray[1][1] == 'X' && displayArray[2][0] == 'X')
        {
            winCheck[0] = true;
        }



       /* if (displayArray[0][0] == 'X' && displayArray[0][1] == 'X' && displayArray[0][2] == 'X')
        {
			winCheck[0] = true;
        }
        if (displayArray[1][0] == 'X' && displayArray[1][1] == 'X' && displayArray[1][2] == 'X')
        {
			winCheck[0] = true;
        }
		if (displayArray[2][0] == 'X' && displayArray[2][1] == 'X' && displayArray[2][2] == 'X')
		{
			winCheck[0] = true;
        }*/
             

        /*if (displayArray[0][0] == 'X' && displayArray[1][0] == 'X' && displayArray[2][0] == 'X')
        {
			winCheck[0] = true;
        }
        if (displayArray[0][1] == 'X' && displayArray[1][1] == 'X' && displayArray[2][1] == 'X')
        {
            winCheck[0] = true;
        }
        if (displayArray[0][2] == 'X' && displayArray[1][2] == 'X' && displayArray[2][2] == 'X')
        {
			winCheck[0] = true;
        }*/

        
        
		//player2 승리조건 체크

		//가로방향 체크
        for (i = 0;i <= 2;++i)
		{
			if (displayArray[i][0] == '@' && displayArray[i][1] == '@' && displayArray[i][2] == '@')
            {
				winCheck[1] = true;
            }
		}

		//세로방향 체크
        for (i = 0; i <= 2; ++i)
        {
            if (displayArray[0][i] == '@' && displayArray[1][i] == '@' && displayArray[2][i] == '@')
            {
                winCheck[1] = true;
            }
        }

		//대각선방향 체크
       if (displayArray[0][0] == '@' && displayArray[1][1] == '@' && displayArray[2][2] == '@')
        {
            winCheck[1] = true;
        }
       
        if (displayArray[0][2] == '@' && displayArray[1][1] == '@' && displayArray[2][0] == '@')
        {
            winCheck[1] = true;
        }


       /* if (displayArray[0][0] == '@' && displayArray[0][1] == '@' && displayArray[0][2] == '@')
        {
            winCheck[1] = true;
        }
        if (displayArray[1][0] == '@' && displayArray[1][1] == '@' && displayArray[1][2] == '@')
        {
            winCheck[1] = true;
        }
        if (displayArray[2][0] == '@' && displayArray[2][1] == '@' && displayArray[2][2] == '@')
        {
            winCheck[1] = true;
        }*/
        
        /*if (displayArray[0][0] == '@' && displayArray[1][0] == '@' && displayArray[2][0] == '@')
        {
            winCheck[1] = true;
        }
        if (displayArray[0][1] == '@' && displayArray[1][1] == '@' && displayArray[2][1] == '@')
        {
            winCheck[1] = true;
        }
        if (displayArray[0][2] == '@' && displayArray[1][2] == '@' && displayArray[2][2] == '@')
        {
            winCheck[1] = true;
        }    */ 
      

        if (winCheck[0]|| winCheck[1])
            break;
    }

    if (winCheck[0] == true)
    {
        printf("Player1 Win!\n");
    }

	else if (winCheck[1] == true)
    {
        printf("Player2 Win!\n");
    }
    //printf("Player %d Win!\n", playerNumber);
    
    
}