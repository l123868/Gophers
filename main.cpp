#include "game.h"
int main()
{
    int cho;
    char yn;
    char **board;
    do
    {
        system("color F1");
        printf("�w��Ө��w�֥��a��~\n"
               "�]1�^�C������\n"
               "�]2�^�}�l�C��\n"
               "�]3�^�����C��\n"
               "�]�п�J�����Ʀr��ܡ^...>");
        scanf("%d", &cho);
        if(cho==1)
        {
            system("cls");
            printf("~~~~~~����~~~~~~\n"
                   "�f���겱���f���A�i�O�]���b�����A\n"
                   "�I�F����A�ɭP�s�~�Ѩa�B�������A\n"
                   "�i�c���a���̤��u�O�Y���f���I\n"
                   "�ٱa�۶ǬV�f��B�r�H�I\n"
                   "�{�b�A�ЧA���_�A���l�l�A�@�_�ӥ����U�c�a���a!!!\n");
            system("pause");
            system("cls");
            printf("�C���}�l�ɡA�Ш̷ӵe���ϥι����Ʀr����}�a�}\n"
                   "�A�ϥι����Ʀr�䥴���a��������\n"
                   "�i�J�C����A�A�i�H�ۦ�]�w���a�����^�X��\n");
        }
        else if(cho==2)
        {
            system("cls");
            start_game(board);
        }
        else if(cho==3)
        {
            system("cls");
            printf("�A�u���n���}�F��QQ�H�]y/n�^...>\n");
            scanf(" %c",&yn);
            if(yn=='y'||yn=='Y')
            {
                system("cls");
                printf("�A��QQ\n");
                break;
            }
            else if(yn=='n'||yn=='N')
            {
                system("cls");
                printf("Ya~~�~��ӥ��a��~~\n");
            }
            else
            {
                system("cls");
                printf("�п�Jy��n���}�C��=~=!\n");
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
