#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Position.h"
#include "Maze.h"
typedef struct
{
    char simbolo_exibido;
    int status;
    Position posicao_inicial_player;
    Position posicao_atual_player;


}Player;
Player * criaPlayer(Maze* maze);
void andar(Player* player,Maze* maze,char key);
void destroiPlayer(Player* player);

#endif // PLAYER_H_INCLUDED
