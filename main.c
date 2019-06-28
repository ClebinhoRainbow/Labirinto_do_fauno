#include <stdio.h>
#include <stdlib.h>
#include "Maze.h"
#include "Player.h"
#include "Enemy.h"
#include "Exit.h"
#define NUMERO_INIMIGOS 4
#define LINHAS 21
#define COLUNAS 21
#define NOME_ARQUIVO "maze1.txt" //arquivo de texto localizado na raiz do projeto

int main()
{
    char key;
    int i;

    Maze *m = criarMaze(LINHAS, COLUNAS);
    carregarDadosDoArquivo(m,NOME_ARQUIVO);

    Player *p;
    Enemy * e;
    Exit * s;

    e=criaInimigo(m);
    p=criaPlayer(m);

    exibirLabirinto(m);

    s=criaExit(m);
    int resposta_sondagem =0;

    while(1)
    {
        for(i=0; i < NUMERO_INIMIGOS; i++)
        {
            if(!tenhoAlvo(&e[i]))
                sondagem(m,&e[i],p);

            andarInimigo(&e[i],m,p);
        }

        scanf("%c",&key);
        __fpurge(stdin);
        andar(p,m,key);

        exibirLabirinto(m);
    }
//

destroiSaida(s);
destroiMaze(m);

return 0;
}
