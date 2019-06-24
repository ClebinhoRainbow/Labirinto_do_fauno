#include "Enemy.h"
#include "Player.h"
#define NUMERO_INIMIGOS 4
#include <stdlib.h>
//era pra  ser7 mas preferi botar 8 ao inves de <= ou >=
//ma funcao sondagem
#define LIMITE_SONDAGEM 8
#include <stdio.h>
Enemy * criaInimigo(Maze* maze)
{
    Enemy* inimigo;
    int i,j,c=0;
    inimigo=(Enemy*)malloc(sizeof(Enemy)*NUMERO_INIMIGOS);
    inimigo[0].simbolo_exibido='1';
    inimigo[0].status=1;
    inimigo[0].capacidade_salto=1;
    inimigo[1].simbolo_exibido='2';
    inimigo[1].status=1;
    inimigo[1].capacidade_salto=1;
    inimigo[2].simbolo_exibido='3';
    inimigo[2].status=1;
    inimigo[2].capacidade_salto=1;
    inimigo[3].simbolo_exibido='4';
    inimigo[3].status=1;
    inimigo[3].capacidade_salto=1;
    for(i=0; i<LINHAS; i++)
    {
        for(j=0; j <COLUNAS; j++)
        {
            if(maze->matriz[i][j].dado==inimigo[c].simbolo_exibido)
            {

                inimigo[c].posisao_inicial_inimigo.x=j;
                inimigo[c].posisao_inicial_inimigo.y=i;
                inimigo[c].posisao_atual_inimigo.x=j;
                inimigo[c].posisao_atual_inimigo.y=i;
                if(c<NUMERO_INIMIGOS)
                {
                    c+=1;
                    i=0;
                    j=0;
                }



            }

        }
    }


    return inimigo;




}
void aumenta_salto_inimigo(Maze* maze,Enemy* enemy)
{
    int i, j;
    for(i=0; i<LINHAS; i++)
    {
        for(j=0; j <COLUNAS; j++)
        {
            ///NAO TERMINEI

        }
    }


}
int sondagem(Maze * maze,Enemy *inimigo,Player * player)
{

    int i,j ;
    for(i=1; i<= LIMITE_SONDAGEM; i++)
    {
        if(maze->matriz[inimigo->posisao_atual_inimigo.y][inimigo->posisao_atual_inimigo.x+i].dado!='#')
        {

            if( maze->matriz[inimigo->posisao_atual_inimigo.y][inimigo->posisao_atual_inimigo.x+i].dado=='X')
            {

                inimigo->alvo.x=player->posicao_atual_player.x+i;
                inimigo->alvo.y=player->posicao_atual_player.y;
                return 1;
                ///return 'd';

            }

        }
        if(maze->matriz[inimigo->posisao_atual_inimigo.y][inimigo->posisao_atual_inimigo.x-i].dado!='#')
        {

            if( maze->matriz[inimigo->posisao_atual_inimigo.y][inimigo->posisao_atual_inimigo.x-i].dado=='X')
            {

                inimigo->alvo.x=player->posicao_atual_player.x-i;
                inimigo->alvo.y=player->posicao_atual_player.y;
                  return 1;
                ///return 'a';
            }

        }
        if(maze->matriz[inimigo->posisao_atual_inimigo.y+i][inimigo->posisao_atual_inimigo.x].dado!='#')
        {

            if( maze->matriz[inimigo->posisao_atual_inimigo.y+i][inimigo->posisao_atual_inimigo.x].dado=='X')
            {

                inimigo->alvo.x=player->posicao_atual_player.x;
                inimigo->alvo.y=player->posicao_atual_player.y+i;
                  return 1;
                ///return 's';
            }

        }
        if(maze->matriz[inimigo->posisao_atual_inimigo.y-i][inimigo->posisao_atual_inimigo.x].dado!='#')
        {

            if( maze->matriz[inimigo->posisao_atual_inimigo.y-i][inimigo->posisao_atual_inimigo.x].dado=='X')
            {

                inimigo->alvo.x=player->posicao_atual_player.x;
                inimigo->alvo.y=player->posicao_atual_player.y-i;
                  return 1;
                ///return 'w';
            }

        }


    }
    return 0;

    ///return '#';
}
void andarInimigo(Enemy* enemy,Maze* maze)
{
    printf("%c o simbolo do inimigo\nta dentro do andarInimigo\n",enemy->simbolo_exibido);
    if(enemy->alvo.x==enemy->posisao_atual_inimigo.x&&enemy->alvo.y==enemy->posisao_atual_inimigo.y)
    {
        printf("Ta no mesmo lugar\n");
    }
    if( enemy->alvo.x==enemy->posisao_atual_inimigo.x && enemy->alvo.y < enemy->posisao_atual_inimigo.y)
    {

        ///Acho que nao precisa desse if porque ja foi verificado se existe o '#' na funcao sondagem
        if(maze->matriz[enemy->posisao_atual_inimigo.y-1][enemy->posisao_atual_inimigo.x].dado!='#')
        {
            printf("oiw\n");
            //printf("%c",maze->matriz[player->posicao_inicial_player.x][player->posicao_inicial_player.y].dado);
            maze->matriz[enemy->posisao_atual_inimigo.y][enemy->posisao_atual_inimigo.x].dado='.';
            maze->matriz[enemy->posisao_atual_inimigo.y-1][enemy->posisao_atual_inimigo.x].dado= enemy->simbolo_exibido;
            enemy->posisao_atual_inimigo.y-=1;
            // printf("%di%dj",player->posicao_atual_player.x,player->posicao_atual_player.y);
        }


    }
if(enemy->alvo.x==enemy->posisao_atual_inimigo.x&&enemy->alvo.y>enemy->posisao_atual_inimigo.y)
    {
        if(maze->matriz[enemy->posisao_atual_inimigo.y+1][enemy->posisao_atual_inimigo.x].dado!='#')
        {
            printf("ois\n");
            maze->matriz[enemy->posisao_atual_inimigo.y][enemy->posisao_atual_inimigo.x].dado='.';
            maze->matriz[enemy->posisao_atual_inimigo.y+1][enemy->posisao_atual_inimigo.x].dado= enemy->simbolo_exibido;
            enemy->posisao_atual_inimigo.y+=1;

        }


    }
    if(enemy->alvo.x<enemy->posisao_atual_inimigo.x && enemy->alvo.y == enemy->posisao_atual_inimigo.y)
    {
        if(maze->matriz[enemy->posisao_atual_inimigo.y][enemy->posisao_atual_inimigo.x-1].dado!='#')
        {
            printf("oia\n");
            maze->matriz[enemy->posisao_atual_inimigo.y][enemy->posisao_atual_inimigo.x].dado='.';
            maze->matriz[enemy->posisao_atual_inimigo.y][enemy->posisao_atual_inimigo.x-1].dado= enemy->simbolo_exibido;
            enemy->posisao_atual_inimigo.x-=1;

        }


    }
    if(enemy->alvo.x>enemy->posisao_atual_inimigo.x && enemy->alvo.y == enemy->posisao_atual_inimigo.y)
    {
        if(maze->matriz[enemy->posisao_atual_inimigo.y][enemy->posisao_atual_inimigo.x+1].dado!='#')
        {
            printf("oid\n");
            maze->matriz[enemy->posisao_atual_inimigo.y][enemy->posisao_atual_inimigo.x].dado='.';
            maze->matriz[enemy->posisao_atual_inimigo.y][enemy->posisao_atual_inimigo.x+1].dado= enemy->simbolo_exibido;
            enemy->posisao_atual_inimigo.x+=1;

        }


    }



}
void salto(Maze* maze);
void rastro(Maze* maze);
///terminar depois
void acaba_com_Player(Maze* maze);
void destroiInimigo(Enemy* inimigo);

