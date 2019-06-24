#include <stdio.h>
#include <stdlib.h>
#include "Maze.h"
#include "Player.h"
#include "Enemy.h"
#include "Exit.h"
#define LINHAS 21
#define COLUNAS 21
#define NOME_ARQUIVO "maze1.txt" //arquivo de texto localizado na raiz do projeto

int main()
{
    char key;
    Maze *m = criarMaze(LINHAS, COLUNAS);
    carregarDadosDoArquivo(m,NOME_ARQUIVO);
    Player *p;
    Enemy * e;
    e=criaInimigo(m);
    p=criaPlayer(m);
    exibirLabirinto(m);
    int resposta_sondagem =0 ;
    while(1)
    {
        scanf("%c",&key);
        __fpurge(stdin);

        andar(p,m,key);
        resposta_sondagem = sondagem(m,&e[3],p);
        if(resposta_sondagem)
        {

            andarInimigo(&e[3],m);
            resposta_sondagem=0;

        }
        exibirLabirinto(m);

    }



    //
    destroiMaze(m);


    return 0;
}
