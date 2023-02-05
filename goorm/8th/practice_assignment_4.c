// [실습과제 8-4] 선형 자료구조 이용 자유 프로젝트

/* 프로젝트 설명 

1. 주제 : 틱택토 게임

2. 이용한 자료 구조 : 배열


3. 기능설명 : 

함수
1. init_board : 판 만들기
2. get_player_move : 게임 플레이(바닥에 말 깔기)
3. disp_board : 출력하기


*/

#include <stdio.h>
#include <stdlib.h>

void init_board(char board[][3]);
int get_player_move(int player, char board[][3]);
void disp_board(char board[][3]);

int main() {
    char board[3][3];
    int quit=0;

    init_board(board); // 보드 생성

    do {
        disp_board(board); 
        quit = get_player_move(0, board);
        disp_board(board);
        quit = get_player_move(1, board);
    } while(quit == 0);

    return 0;
}

void init_board(char board[][3])
{
    int x, y;
    for(x=0; x<3; x++)
    {
        for(y=0; y<3; y++)
        {
            board[x][y] = ' ';
        }
    }
}

int get_player_move(int player, char board[3][3])
{
    int x, y, done = 0;

    while(done != 1)
    {
        printf("(x, y) 좌표(종료-1, -1): ");
        scanf("%d,%d",&x, &y);

        if(x == -1 && y == -1)
            return 1;

        if(board[x][y] == ' ')
            break;
        else
            printf("잘못된 위치입니다.\n");
    }

    if(player == 0)
        board[x][y] = 'X';
    else
        board[x][y] = 'O';
    return 0;
}

void disp_board(char board[3][3])
{
    int i;

    for(i=0; i<3; i++)
    {
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        printf("---|---|---\n");
    }
}