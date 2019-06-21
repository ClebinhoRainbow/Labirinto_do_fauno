#include <stdio.h>
#include <stdlib.h>
#include "Maze.h"
#include "Player.h"
#define LINHAS 21
#define COLUNAS 21
#define NOME_ARQUIVO "maze4.txt" //arquivo de texto localizado na raiz do projeto

int main()
{
    char key;
    Maze *m = criarMaze(LINHAS, COLUNAS);
    carregarDadosDoArquivo(m,NOME_ARQUIVO);
      Player *p;
    p=criaPlayer(m);
    //
while(1)
{
scanf("%c",&key);
__fpurge(stdin);
andar(p,m,key);
exibirLabirinto(m);

}



    //
        destroiMaze(m);


    return 0;
}
