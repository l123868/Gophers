#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "game.h"
int main()
{
    int cho;
    char yn,board[3][31]= {""};
    do
    {
        system("color F1");
        printf("歡迎來到歡樂打地鼠~\n"
               "（1）遊戲說明\n"
               "（2）開始遊戲\n"
               "（3）結束遊戲\n"
               "（請輸入對應數字選擇）...>");
        scanf("%d", &cho);
        if(cho==1)
        {
            system("cls");
            printf("~~~~~~說明~~~~~~\n"
                   "番薯國盛產番薯，可是因為在位國王，\n"
                   "施政失當，導致連年天災、鼠輩橫行，\n"
                   "可惡的地鼠們不只是吃光番薯！\n"
                   "還帶著傳染病到處咬人！\n"
                   "現在，請你拿起你的槌子，一起來打擊萬惡地鼠吧!!!\n");
            system("pause");
            system("cls");
            printf("遊戲開始時，請依照畫面使用對應數字鍵挖開地洞\n"
                   "再使用對應數字鍵打擊地鼠ˊˇˋ\n"
                   "進入遊戲後，你可以自行設定打地鼠的回合數\n");
        }
        else if(cho==2)
        {
            system("cls");
            start_game(board);
        }
        else if(cho==3)
        {
            system("cls");
            printf("你真的要離開了嗎QQ？（y/n）...>\n");
            scanf(" %c",&yn);
            if(yn=='y'||yn=='Y')
            {
                system("cls");
                printf("再見QQ\n");
                break;
            }
            else if(yn=='n'||yn=='N')
            {
                system("cls");
                printf("Ya~~繼續來打地鼠~~\n");
            }
            else
            {
                system("cls");
                printf("請輸入y或n離開遊戲=~=!\n");
                if(yn=='y'||yn=='Y')
                    break;
                else if(yn=='n'||yn=='N')
                    continue;
            }
        }
        system("pause");
        system("cls");
    }
    while(cho!=3||(yn!='y'||yn!='Y'));
    return 0;
}
