#ifndef EXIT_H_INCLUDED
#define EXIT_H_INCLUDED
#include "Position.h"
#include "Maze.h"
#include "Player.h"
typedef struct
{
    char simbolo_exibido;
    Position posicao_saida_matriz;

}Exit;
Exit* criaExit(Maze*m);
int jogadorVenceu(Exit* e,Player*p);
void destroiSaida(Exit* saida);

#endif // EXIT_H_INCLUDED
