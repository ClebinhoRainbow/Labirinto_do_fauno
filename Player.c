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

                jogador->posicao_inicial_player.x=i;
                jogador->posicao_inicial_player.y=j;

            }

        }
    }

    return jogador;
}
/*
87w
65a
68d
83s
*/
void andar(Player* player,Maze* maze,char key)
{

    int espaco_livre=0;
    if((int)key==87)
    {

        if(((player->posicao_inicial_player.y)+1)>LINHAS)
        {
            if( maze->matriz[player->posicao_inicial_player.x][(player->posicao_inicial_player.y)+1].dado!='#')
            {
                   player->posicao_inicial_player.y+=1;
            }
        }

    }
    if((int)key==65);
    if((int)key==68);
    if((int)key==83);

}
void destroiPlayer(Player* player);
//funcao verifica_espaco_livre retorna 1 se o proximo movimento e possivel


