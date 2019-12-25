#include "game.h"
Shrewmice m;
void create_board(char **&p)
{
    p = (char**)malloc(sizeof(char*) * m.size);
    for (int i = 0; i < m.size; i+=1)
        p[i] = (char*)malloc(sizeof(char) * (m.size*10+1));
}
void destroy_board(char **&p)
{
    for (int j = 0; j < m.size*10+1; j+=1)
        free(p[j]);
    free(p);
}
void Shrewmice::create_Shrewmice()
{
    has_shrewmouse = (bool**)malloc(sizeof(bool*) * size);
    for (int i = 0; i < size; i+=1)
        has_shrewmouse[i] = (bool*)malloc(sizeof(bool) * size);

    is_alive = (bool**)malloc(sizeof(bool*) * size);
    for (int i = 0; i < size; i+=1)
        is_alive[i] = (bool*)malloc(sizeof(bool) * size);

    alive_time = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i+=1)
        alive_time[i] = (int*)malloc(sizeof(int) * size);

    dead_time = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i+=1)
        dead_time[i] = (int*)malloc(sizeof(int) * size);

    appearance = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i+=1)
        appearance[i] = (int*)malloc(sizeof(int) * size);
}
// 贺薄

void Shrewmice::shrewmice_clean()
{
    for (int i = 0; i < size; i+=1)
        for (int j = 0; j < size; j+=1)
            has_shrewmouse[i][j] = false;
}

void Shrewmice::shrewmouse_hit(int i,int j)
{
    is_alive[i][j] = false; // 奔
    dead_time[i][j] = 0;    // 北QwQ陪ボ碭
}

void Shrewmice::shrewmouse_create(int i, int j)
{
    has_shrewmouse[i][j] = true;
    is_alive[i][j] = true;
    alive_time[i][j] = 0;   // ╡
    appearance[i][j] = rand()%6;
}

void Shrewmice::shrewmice_update()
{
    // 穝场公
    for (int i = 0; i < size; i+=1)
    {
        for (int j = 0; j < size; j+=1)
        {
            // 狦Τ公 (i,j)
            if (has_shrewmouse[i][j])
            {
                if (is_alive[i][j])
                {
                    alive_time[i][j]+=1;
                    // 6ア
                    if (alive_time[i][j] > 6)
                        has_shrewmouse[i][j] = false;
                }
                else
                {
                    dead_time[i][j]+=1;
                    // 2ア
                    if (dead_time[i][j] > 2)
                        has_shrewmouse[i][j] = false;
                }
            }
        }
    }
}

void print_table_new(Shrewmice m)
{
    //絃
    int i,j,k;
    char **p;
    create_board(p);
    blank(p);
    face(p);
    system("cls");
    for(i=0; i<m.size; i+=1)
        for(int j=0; j<m.size; j+=1)
            p[i][j*10+10]='|';
    for(i=0; i<m.size*10+1; i+=1)
    {
        printf("_");
    }
    printf("\n");
    for(i=0; i<m.size; i+=1)
    {
        for(j=0; j<m.size*10+1; j+=1)
        {
            printf("%c",p[i][j]);
        }
        printf("\n");
        for(k=0; k<m.size*10+1; k+=1)
        {
            printf("_");
        }
        printf("\n");
    }
}

void start_game(char **&p)
{
    int time,num;
    system("cls");
    printf("稱璶絃...>\n");
    scanf("%d", &m.size);
    system("cls");
    printf("稱碭...>\n");
    scanf("%d", &time);
    system("cls");
    printf("程Ω瞷碭唉公...>\n");
    scanf("%d", &num);
    create_board(p);
    blank(p);
    set_table(p);
    print_table(p);
    clean(p);
    run1(time,num);
}
void set_table(char **&p)
{
    int i,j,k;
    //恶计
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
void print_table(char **&p)
{
    //絃
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
void clean(char **&p)
{
    //make wholes
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
void blank(char **&p)
{
    //make the board blank
    for(int i=0; i<m.size; i+=1)
    {
        for(int j=0; j<(m.size*10+1); j+=1)
        {
            p[i][j]=' ';
        }
    }
}
int Shrewmice::hit_new(char k)
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
    m.shrewmice_clean();
    do
    {
        m.shrewmice_update();
        live=0;
        for (int i=0; i<3; i+=1)
            for (int j=0; j<3; j+=1)
                if (m.has_shrewmouse[i][j])
                    live+=1;
        while (live < n)
        {
            int x=rand()%3;
            int y=rand()%3;
            if (!m.has_shrewmouse[x][y])
            {
                m.shrewmouse_create(x,y);
                live+=1;
            }
        }
        print_table_new(m);
        char k;
        Sleep(500);
        if(kbhit())
        {
            k=getch();
            if(m.hit_new(k))
            {
                score+=1;
            }
        }
        i-=1;
    }
    while(i>0);
    printf("ゴ%d唉公\n", score);
}
void appear(char **p, int n)
{
    //瞷公よ
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
void face(char **&p)
{
    int *col;
    col=(int*)malloc(sizeof(int)*m.size);
    for(int i=0; i<m.size; i+=1)
        col[i]= (i+1)*5;
    for(int i=0; i<m.size; i+=1)
    {
        for (int j=0; j<m.size; j+=1)
        {
            if (m.has_shrewmouse[i][j])
            {
                if (m.is_alive[i][j])
                {
                    for (int k=0; k<3; k+=1)
                    {
                        p[i][col[j]-1+k] = m.appearances[m.appearance[i][j]][k];
                    }
                }
                else
                {
                    p[i][col[j]-1] = 'Q';
                    p[i][col[j]] = 'w';
                    p[i][col[j]+1] = 'Q';
                }
            }
        }
    }
}

