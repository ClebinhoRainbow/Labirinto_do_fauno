#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "Position.h"
#include "Maze.h"
#define LINHAS 21
#define COLUNAS 21
#include "Player.h"
typedef struct
{
    char simbolo_exibido;
    int status;
    int capacidade_salto;
    Position alvo;
    Position posisao_inicial_inimigo;
    Position posisao_atual_inimigo;

} Enemy;
Enemy * criaInimigo(Maze* maze);
void aumenta_salto_inimigo(Maze* maze,Enemy* enemy);
int andarInimigo(Enemy* enemy,Maze* maze,Player * player);
int sondagem(Maze * maze,Enemy *inimigo,Player * player);
void Salto(Maze* maze);
void rastro(Maze* maze);
void destroiInimigo(Enemy* inimigo);


#endif // ENEMY_H_INCLUDED
