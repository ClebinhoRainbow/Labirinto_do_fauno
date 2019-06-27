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
    int i ;
    Maze *m = criarMaze(LINHAS, COLUNAS);
    carregarDadosDoArquivo(m,NOME_ARQUIVO);
    Player *p;
    Enemy * e;
    Exit * s;
    e=criaInimigo(m);
    p=criaPlayer(m);
    exibirLabirinto(m);
    s=criaExit(m);
    int resposta_sondagem =0 ;
    while(jogadorVenceu(s,p))
    {
        scanf("%c",&key);
        __fpurge(stdin);
        andar(p,m,key);
        for(i=0; i<=NUMERO_INIMIGOS; i++)
        {

            resposta_sondagem = sondagem(m,&e[i],p);
           /// printf("Respost sondagem %d\n",resposta_sondagem);
            if(resposta_sondagem)
               {


                while(!andarInimigo(&e[i],m,p))
                {

                    exibirLabirinto(m);
                  ///  printf("dentro do andar inimigo\n");

                }
             ///   printf("sai do andar inimig\n");

               }


        }
    ///    printf("fora\n");



        exibirLabirinto(m);

    }
    printf("O jogador venceu");



    //


    destroiSaida(s);
    destroiMaze(m);


    return 0;
}
