#include "Exit.h"
#define LINHAS 21
#define COLUNAS 21
#include <stdio.h>
Exit* criaExit(Maze*m)
{
int i , j;
Exit * saida;
saida=(Exit*)malloc(sizeof(Exit));
saida->simbolo_exibido='S';
    for(i=0; i<LINHAS; i++)
    {
        for(j=0; j <COLUNAS; j++)
        {
            if(m->matriz[i][j].dado==saida->simbolo_exibido)
            {

                saida->posicao_saida_matriz.x= i;
                saida->posicao_saida_matriz.y= j;



            }

        }
    }
    return saida;

}
int jogadorVenceu(Exit* e,Player*p)
{

    if(p->posicao_atual_player.x == e->posicao_saida_matriz.x && e->posicao_saida_matriz.y == p->posicao_atual_player.y)
    return 0;
    else
    return 1;

}
void destroiSaida(Exit* saida)
{

free(saida);
}
