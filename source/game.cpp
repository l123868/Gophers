#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "game.h"

bool has_shrewmouse[3][3];
bool is_alive[3][3];
int alive_time[3][3];
int dead_time[3][3];
int appearance[3][3];

// 各種表情
const char* appearances[6] = {"AwA", "OAO", "O_O", "=A=","=w=","OoO"};

void shrewmice_clean() {
    for (int i = 0; i < 3; i+=1)
        for (int j = 0; j < 3; j+=1)
            has_shrewmouse[i][j] = false;
}

void shrewmouse_hit(int i, int j) {
    is_alive[i][j] = false; // 死掉
    dead_time[i][j] = 0;    // 死多久了，控制QwQ顯示幾回合
}

void shrewmouse_create(int i, int j) {
    has_shrewmouse[i][j] = true;
    is_alive[i][j] = true;
    alive_time[i][j] = 0;   // 牠活了多久
    appearance[i][j] = rand()%6;
}

void shrewmice_update() {
    // 更新全部的地鼠
    for (int i = 0; i < 3; i+=1) {
        for (int j = 0; j < 3; j+=1) {
            // 如果有地鼠在 (i,j)
            if (has_shrewmouse[i][j]) {
                if (is_alive[i][j]) {
                    alive_time[i][j]+=1;
                    // 6回合後消失
                    if (alive_time[i][j] > 6)
                        has_shrewmouse[i][j] = false;
                } else {
                    dead_time[i][j]+=1;
                    // 2回合後消失
                    if (dead_time[i][j] > 2)
                        has_shrewmouse[i][j] = false;
                }
            }
        }
    }
}

void print_table_new()
{
    //印出盤面
    int i,j,k;
    char p[3][31];
    blank(p);
    face(p);
    system("cls");
    for(i=0; i<3; i+=1)
    {
        p[i][0]='|';
        p[i][10]='|';
        p[i][20]='|';
        p[i][30]='|';
    }
    for(i=0; i<31; i+=1)
    {
        printf("_");
    }
    printf("\n");
    for(i=0; i<3; i+=1)
    {
        for(j=0; j<31; j+=1)
        {
            printf("%c",p[i][j]);
        }
        printf("\n");
        for(k=0; k<31; k+=1)
        {
            printf("_");
        }
        printf("\n");
    }
}

void start_game(char (*p)[31])
{
        int time,num;
        system("cls");
        printf("你想玩幾回合？...>\n");
        scanf("%d", &time);
        system("cls");
        printf("最多一次出現幾隻地鼠？...>\n");
        scanf("%d", &num);
        blank(p);
        set_table(p);
        print_table(p);
        clean(p);
        run1(time,num);
}
void set_table(char (*p)[31])
{
    int i,j,k;
    //填入數字
    p[0][5]='7';
    p[0][15]='8';
    p[0][25]='9';

    p[1][5]='4';
    p[1][15]='5';
    p[1][25]='6';

    p[2][5]='1';
    p[2][15]='2';
    p[2][25]='3';
}
void print_table(char (*p)[31])
{
    //印出盤面
    int i,j,k;
    system("cls");
    for(i=0; i<3; i+=1)
    {
        p[i][0]='|';
        p[i][10]='|';
        p[i][20]='|';
        p[i][30]='|';
    }
    for(i=0; i<31; i+=1)
    {
        printf("_");
    }
    printf("\n");
    for(i=0; i<3; i+=1)
    {
        for(j=0; j<31; j+=1)
        {
            printf("%c",p[i][j]);
        }
        printf("\n");
        for(k=0; k<31; k+=1)
        {
            printf("_");
        }
        printf("\n");
    }
}
void clean(char (*p)[31])
{
    //挖洞
    char ch;
    do
    {
        ch=getch();
        if(ch==p[0][5])
            p[0][5]=' ';
        else if(ch==p[0][15])
            p[0][15]=' ';
        else if(ch==p[0][25])
            p[0][25]=' ';

        if(ch==p[1][5])
            p[1][5]=' ';
        else if(ch==p[1][15])
            p[1][15]=' ';
        else if(ch==p[1][25])
            p[1][25]=' ';

        if(ch==p[2][5])
            p[2][5]=' ';
        else if(ch==p[2][15])
            p[2][15]=' ';
        else if(ch==p[2][25])
            p[2][25]=' ';
        print_table(p);
        if(p[0][5]==p[0][15]&&
                p[0][15]==p[0][25]&&
                p[0][25]==p[1][5]&&
                p[1][5]==p[1][15]&&
                p[1][15]==p[1][25]&&
                p[1][25]==p[2][5]&&
                p[2][5]==p[2][15]&&
                p[2][15]==p[2][25])
            break;
    }
    while(1);
}
void blank(char (*p)[31])
{
    //清空盤面
    for(int i=0; i<3; i+=1)
    {
        for(int j=0; j<31; j+=1)
        {
            p[i][j]=' ';
        }
    }
}
int hit_new(char k)
{
    if(k=='7'&&has_shrewmouse[0][0]&&is_alive[0][0])
    {
        shrewmouse_hit(0,0);
        return 1;
    }
    else if (k=='8'&&has_shrewmouse[0][1]&&is_alive[0][1])
    {
        shrewmouse_hit(0,1);
        return 1;
    }
    else if (k=='9'&&has_shrewmouse[0][2]&&is_alive[0][2])
    {
        shrewmouse_hit(0,2);
        return 1;
    }
    else if (k=='4'&&has_shrewmouse[1][0]&&is_alive[1][0])
    {
        shrewmouse_hit(1,0);
        return 1;
    }
    else if (k=='5'&&has_shrewmouse[1][1]&&is_alive[1][1])
    {
        shrewmouse_hit(1,1);
        return 1;
    }
    else if (k=='6'&&has_shrewmouse[1][2]&&is_alive[1][2])
    {
        shrewmouse_hit(1,2);
        return 1;
    }
    else if (k=='1'&&has_shrewmouse[2][0]&&is_alive[2][0])
    {
        shrewmouse_hit(2,0);
        return 1;
    }
    else if (k=='2'&&has_shrewmouse[2][1]&&is_alive[2][1])
    {
        shrewmouse_hit(2,1);
        return 1;
    }
    else if (k=='3'&&has_shrewmouse[2][2]&&is_alive[2][2])
    {
        shrewmouse_hit(2,2);
        return 1;
    }
    else
    {
        return 0;
    }
}
void run1(int t,int n)
{
    int i=t*2,score=0,live;
    shrewmice_clean();
    do
    {
        shrewmice_update();
        live=0;
        for (int i=0; i<3; i+=1)
            for (int j=0; j<3; j+=1)
                if (has_shrewmouse[i][j])
                    live+=1;
        while (live < n) {
            int x=rand()%3;
            int y=rand()%3;
            if (!has_shrewmouse[x][y]) {
                shrewmouse_create(x,y);
                live+=1;
            }
        }
        print_table_new();
        char k;
        Sleep(500);
        if(kbhit())
        {
            k=getch();
            if(hit_new(k))
            {
                score+=1;
            }
        }
        i-=1;
    }
    while(i>0);
    printf("你成功打死%d隻地鼠！\n", score);
}
void appear(char(*p)[31], int n)
{
    //出現地鼠的地方
    int row[3]= {0,1,2},col[3]= {5,15,25},x,y;
    for(int i=0; i<n; i+=1)
    {
        x=rand()%3;
        y=rand()%3;
        p[row[x]][col[y]]='O';
    }
}

int hit(char (*p)[31],char k)
{
    if(k=='7'&&p[0][5]!=' ')
    {
        p[0][5]='X';
        return 1;
    }
    else if(k=='8'&&p[0][15]!=' ')
    {
        p[0][15]='X';
        return 1;
    }
    else if(k=='9'&&p[0][25]!=' ')
    {
        p[0][25]='X';
        return 1;
    }
    else if(k=='4'&&p[1][5]!=' ')
    {
        p[1][5]='X';
        return 1;
    }
    else if(k=='5'&&p[1][15]!=' ')
    {
        p[1][15]='X';
        return 1;
    }
    else if(k=='6'&&p[1][25]!=' ')
    {
        p[1][25]='X';
        return 1;
    }
    else if(k=='1'&&p[2][5]!=' ')
    {
        p[2][5]='X';
        return 1;
    }
    else if(k=='2'&&p[2][15]!=' ')
    {
        p[2][15]='X';
        return 1;
    }
    else if(k=='3'&&p[2][25]!=' ')
    {
        p[2][25]='X';
        return 1;
    }
    else
    {
        return 0;
    }
}
void face(char (*p)[31])
{
    int row[3]= {0,1,2},col[3]= {5,15,25};
    for(int i=0; i<3; i+=1)
    {
        for (int j=0; j<3; j+=1)
        {
            if (has_shrewmouse[i][j])
            {
                if (is_alive[i][j])
                {
                    for (int k=0; k<3; k+=1)
                    {
                        p[row[i]][col[j]-1+k] = appearances[appearance[i][j]][k];
                    }
                }
                else
                {
                    p[row[i]][col[j]-1] = 'Q';
                    p[row[i]][col[j]] = 'w';
                    p[row[i]][col[j]+1] = 'Q';
                }
            }
        }
    }
}
