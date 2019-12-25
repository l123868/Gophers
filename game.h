#ifndef GAME_
#define GAME_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
struct Shrewmice
{
    int size=0;
    bool **has_shrewmouse;
    bool **is_alive;
    int **alive_time;
    int **dead_time;
    int **appearance;
    const char* appearances[6] = {"AwA", "OAO", "O_O", "=A=","=w=","OoO"};
    void create_Shrewmice();
    void shrewmice_clean();
    void shrewmouse_hit(int i,int j);
    void shrewmouse_create(int i,int j) ;
    void shrewmice_update() ;
    int hit_new(char k);
};
void create_board(char **&p);
void destroy_board(char **&P);
void print_table_new(Shrewmice m);
void start_game(char **&p);
void set_table(char **&p);
void print_table(char **&p);
void clean(char **&p);
void blank(char **&p);

void run1(int t,int n);
void appear(char**&p, int n);
int hit(char **&p,char k);
void face(char **&p);

#endif // GAME_


