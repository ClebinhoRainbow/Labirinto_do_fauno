#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "Position.h"
#include "Maze.h"
typedef struct
{
     char simbolo_exibido;
    int status;
    int capacidade_salto;
    Position alvo;
    Position posisao_inicial_inimigo;
    Position posisao_atual_inimigo;

}Enemy;


#endif // ENEMY_H_INCLUDED
