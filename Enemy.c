#include "Enemy.h"
#include "Player.h"
#define NUMERO_INIMIGOS 4
#include <stdlib.h>
#define LINHAS 21
#define COLUNAS 21
#define LIMITE_SONDAGEM 7
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

                inimigo[c].posisao_inicial_inimigo.x=i;
                inimigo[c].posisao_inicial_inimigo.y=j;
                inimigo[c].posisao_atual_inimigo.x=i;
                inimigo[c].posisao_atual_inimigo.y=j;

                inimigo[c].alvo.x = -1;
                inimigo[c].alvo.y = -1;

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
///   maze->matriz[inimigo->posisao_atual_inimigo.x][inimigo->posisao_atual_inimigo.y-3].dado='1';///esquerda
///    maze->matriz[inimigo->posisao_atual_inimigo.x][inimigo->posisao_atual_inimigo.y+3].dado='2';///direita
 ///   maze->matriz[inimigo->posisao_atual_inimigo.x-3][inimigo->posisao_atual_inimigo.y].dado='3';///cima
///    maze->matriz[inimigo->posisao_atual_inimigo.x+3][inimigo->posisao_atual_inimigo.y].dado='4';///baixo


int sondagem(Maze * maze,Enemy *inimigo,Player * player)
{
//printf("sondagem\n");
    int i,flag_A=1,flag_D=1,flag_S=1,flag_W=1;


    for(i=0; i<=LIMITE_SONDAGEM; i++)
    {
        if((inimigo->posisao_atual_inimigo.y-1) > 0)
        {
            if(maze->matriz[inimigo->posisao_atual_inimigo.x][inimigo->posisao_atual_inimigo.y-i].dado !='#' && flag_W)
            {
                if(maze->matriz[inimigo->posisao_atual_inimigo.x][inimigo->posisao_atual_inimigo.y-i].dado =='X')
                {
                    inimigo->alvo.x = inimigo->posisao_atual_inimigo.x;
                    inimigo->alvo.y = inimigo->posisao_atual_inimigo.y-i;
                    return 1;
                }
            }
            else if(maze->matriz[inimigo->posisao_atual_inimigo.x][inimigo->posisao_atual_inimigo.y-i].dado == '#')
                flag_W=0;
        }
        if((inimigo->posisao_atual_inimigo.y+1) < LINHAS)
        {
            if(maze->matriz[inimigo->posisao_atual_inimigo.x][inimigo->posisao_atual_inimigo.y+i].dado != '#' && flag_D)
            {
                if(maze->matriz[inimigo->posisao_atual_inimigo.x][inimigo->posisao_atual_inimigo.y+i].dado == 'X')
                {
                    inimigo->alvo.x=inimigo->posisao_atual_inimigo.x;
                    inimigo->alvo.y=inimigo->posisao_atual_inimigo.y+i;
                    return 1;
                }
            }
            else if(maze->matriz[inimigo->posisao_atual_inimigo.x][inimigo->posisao_atual_inimigo.y+i].dado == '#')
                flag_D=0;
        }
        if((inimigo->posisao_atual_inimigo.x-i) > 0)
        {
            if(maze->matriz[inimigo->posisao_atual_inimigo.x-i][inimigo->posisao_atual_inimigo.y].dado != '#' && flag_A)
            {
                if(maze->matriz[inimigo->posisao_atual_inimigo.x-i][inimigo->posisao_atual_inimigo.y].dado =='X')
                {
                    inimigo->alvo.x=inimigo->posisao_atual_inimigo.x-i;
                    inimigo->alvo.y=inimigo->posisao_atual_inimigo.y;
                    return 1;
                }
            }
            else if(maze->matriz[inimigo->posisao_atual_inimigo.x-i][inimigo->posisao_atual_inimigo.y].dado != '#' )
                flag_A=0;
        }
        if((inimigo->posisao_atual_inimigo.x+i) < COLUNAS)
        {
            if(maze->matriz[inimigo->posisao_atual_inimigo.x+i][inimigo->posisao_atual_inimigo.y].dado != '#' && flag_S)
            {
                if(maze->matriz[inimigo->posisao_atual_inimigo.x+i][inimigo->posisao_atual_inimigo.y].dado == 'X')
                {
                    inimigo->alvo.x=inimigo->posisao_atual_inimigo.x+i;
                    inimigo->alvo.y=inimigo->posisao_atual_inimigo.y;
                    return 1;
                }
            }
            else if(maze->matriz[inimigo->posisao_atual_inimigo.x+i][inimigo->posisao_atual_inimigo.y].dado == '#')
                flag_S=0;
        }
    }
    return 0;
}

void andarInimigo(Enemy* enemy,Maze* maze,Player * player)
{
    if(((enemy->alvo.x != enemy->posisao_atual_inimigo.x) && (enemy->alvo.x != -1)) || ((enemy->alvo.y != enemy->posisao_atual_inimigo.y) && (enemy->alvo.y != -1)))
    {
        if((enemy->alvo.x > enemy->posisao_atual_inimigo.x) && (maze->matriz[enemy->posisao_atual_inimigo.x+1][enemy->posisao_atual_inimigo.y].dado != '#'))
        {
            maze->matriz[enemy->posisao_atual_inimigo.x][enemy->posisao_atual_inimigo.y].dado='.';
            maze->matriz[enemy->posisao_atual_inimigo.x+1][enemy->posisao_atual_inimigo.y].dado = enemy->simbolo_exibido;
            enemy->posisao_inicial_inimigo.y = enemy->posisao_atual_inimigo.y;
            enemy->posisao_inicial_inimigo.x = enemy->posisao_atual_inimigo.x;
            enemy->posisao_atual_inimigo.x += 1;
        }
        if((enemy->alvo.x < enemy->posisao_atual_inimigo.x) && (maze->matriz[enemy->posisao_atual_inimigo.x-1][enemy->posisao_atual_inimigo.y].dado != '#'))
        {
            maze->matriz[enemy->posisao_atual_inimigo.x][enemy->posisao_atual_inimigo.y].dado = '.';
            maze->matriz[enemy->posisao_atual_inimigo.x-1][enemy->posisao_atual_inimigo.y].dado = enemy->simbolo_exibido;
            enemy->posisao_inicial_inimigo.y = enemy->posisao_atual_inimigo.y;
            enemy->posisao_inicial_inimigo.x = enemy->posisao_atual_inimigo.x;
            enemy->posisao_atual_inimigo.x -= 1;
        }
        if((enemy->alvo.y > enemy->posisao_atual_inimigo.y) && (maze->matriz[enemy->posisao_atual_inimigo.x][enemy->posisao_atual_inimigo.y+1].dado != '#'))
        {
            maze->matriz[enemy->posisao_atual_inimigo.x][enemy->posisao_atual_inimigo.y].dado = '.';
            maze->matriz[enemy->posisao_atual_inimigo.x][enemy->posisao_atual_inimigo.y+1].dado = enemy->simbolo_exibido;
            enemy->posisao_inicial_inimigo.y = enemy->posisao_atual_inimigo.y;
            enemy->posisao_inicial_inimigo.x = enemy->posisao_atual_inimigo.x;
            enemy->posisao_atual_inimigo.y += 1;
        }
        if((enemy->alvo.y < enemy->posisao_atual_inimigo.y) && (maze->matriz[enemy->posisao_atual_inimigo.x][enemy->posisao_atual_inimigo.y-1].dado != '#'))
        {
            maze->matriz[enemy->posisao_atual_inimigo.x][enemy->posisao_atual_inimigo.y].dado = '.';
            maze->matriz[enemy->posisao_atual_inimigo.x][enemy->posisao_atual_inimigo.y-1].dado = enemy->simbolo_exibido;
            enemy->posisao_inicial_inimigo.y=enemy->posisao_atual_inimigo.y;
            enemy->posisao_inicial_inimigo.x=enemy->posisao_atual_inimigo.x;
            enemy->posisao_atual_inimigo.y -= 1;
        }
    }
    else
    {
        enemy->alvo.x = -1;
        enemy->alvo.y = -1;
    }
}
///Problemas aqui
void salto(Maze* maze)
{
    int salto=1;
    int i , j;
    for(i=0; i<LINHAS; i++)
    {
        for(j=0; j <COLUNAS; j++)
        {
            if(1)
            {




            }

        }
    }



}
void rastro(Maze* maze);

void destroiInimigo(Enemy* inimigo)
{
    free(inimigo);
}

int tenhoAlvo(Enemy * inimigo)
{
    if((inimigo->alvo.x == -1) || (inimigo->alvo.y == -1))
        return 0;
    else
        return 1;
}
