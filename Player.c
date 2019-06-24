#include "Player.h"
#include <stdlib.h>
#define LINHAS 21
#define COLUNAS 21

Player * criaPlayer(Maze* maze)
{
    Player * jogador;
    int i, j;
    jogador=(Player*)malloc(sizeof(Player));
    jogador->simbolo_exibido='X';
    jogador->status=1;

    for(i=0; i<LINHAS; i++)
    {
        for(j=0; j <COLUNAS; j++)
        {
            if(maze->matriz[i][j].dado==jogador->simbolo_exibido)
            {

                jogador->posicao_inicial_player.x=j;
                jogador->posicao_inicial_player.y=i;
                jogador->posicao_atual_player.x=j;
                jogador->posicao_atual_player.y=i;
                ///printf("%di%dj",jogador->posicao_inicial_player.x,jogador->posicao_inicial_player.y);

            }

        }
    }

    return jogador;
}
void andar(Player* player,Maze* maze,char key)
{
    /*
    maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x+1].dado='1';//d
    maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x-1].dado='2';//a
    maze->matriz[player->posicao_atual_player.y+1][player->posicao_atual_player.x].dado='3';//s
    maze->matriz[player->posicao_atual_player.y-1][player->posicao_atual_player.x].dado='4';//w
    */
    if(key=='w'||key=='W')
    {
        if(maze->matriz[player->posicao_atual_player.y-1][player->posicao_atual_player.x].dado!='#')
        {
            //printf("%c",maze->matriz[player->posicao_inicial_player.x][player->posicao_inicial_player.y].dado);
            maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x].dado='.';
            maze->matriz[player->posicao_atual_player.y-1][player->posicao_atual_player.x].dado= 'X';
            player->posicao_inicial_player.y=player->posicao_atual_player.y;
            player->posicao_inicial_player.x=player->posicao_atual_player.x;
            player->posicao_atual_player.y-=1;
            // printf("%di%dj",player->posicao_atual_player.x,player->posicao_atual_player.y);
        }


    }
    if(key=='s'||key=='S')
    {
        if(maze->matriz[player->posicao_atual_player.y+1][player->posicao_atual_player.x].dado!='#')
        {
            maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x].dado='.';
            maze->matriz[player->posicao_atual_player.y+1][player->posicao_atual_player.x].dado= 'X';
              player->posicao_inicial_player.y=player->posicao_atual_player.y;
            player->posicao_inicial_player.x=player->posicao_atual_player.x;
            player->posicao_atual_player.y+=1;

        }


    }
    if(key=='a'||key=='A')
    {
        if(maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x-1].dado!='#')
        {
            maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x].dado='.';
            maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x-1].dado= 'X';
              player->posicao_inicial_player.y=player->posicao_atual_player.y;
            player->posicao_inicial_player.x=player->posicao_atual_player.x;
            player->posicao_atual_player.x-=1;

        }


    }
    if(key=='d'||key=='D')
    {
        if(maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x+1].dado!='#')
        {
            maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x].dado='.';
            maze->matriz[player->posicao_atual_player.y][player->posicao_atual_player.x+1].dado= 'X';
            player->posicao_inicial_player.y=player->posicao_atual_player.y;
            player->posicao_inicial_player.x=player->posicao_atual_player.x;
            player->posicao_atual_player.x+=1;

        }


    }


}
void destroiPlayer(Player* player)
{
    free(player);

}
//funcao verifica_espaco_livre retorna 1 se o proximo movimento e possivel


