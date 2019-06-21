#include "Maze.h"
#include <stdlib.h>
#include <stdio.h>

Maze * criarMaze(int linhas, int colunas)
{
    //aloca um TAD do tipo MAZE
    Maze *m = (Maze *) malloc(sizeof(Maze));

    if(m != NULL)
    {
        int i;

        m->linhas = linhas;
        m->colunas = colunas;

        //aloca o vetor de vetores para armazenar as linhas da matriz
        m->matriz = (Position **) malloc(sizeof(Position *) * linhas);

        for(i = 0; i < linhas; i++)
        {
            //aloca cada linha da matriz
            m->matriz[i] = (Position *) malloc(sizeof(Position) * colunas);
        }
    }
    return m;
}

void carregarDadosDoArquivo(Maze *maze, char * nomeArquivo)
{
    int playerX, playerY;
    int monstro1X, monstro1Y;
    int monstro2X, monstro2Y;
    int monstro3X, monstro3Y;
    int monstro4X, monstro4Y;
    int saidaX, saidaY;

    FILE *file = fopen(nomeArquivo, "r");

    if(file == NULL)
    {
        printf("erro ao abrir o arquivo - confira o nome ou o local onde o arquivo maze.txt foi salvo\n");
    }
    else
    {
        ///carregando elementos----------------------------
        fscanf(file, "%d %d\n", &playerX, &playerY);
        fscanf(file, "%d %d\n", &monstro1X, &monstro1Y);
        fscanf(file, "%d %d\n", &monstro2X, &monstro2Y);
        fscanf(file, "%d %d\n", &monstro3X, &monstro3Y);
        fscanf(file, "%d %d\n", &monstro4X, &monstro4Y);
        fscanf(file, "%d %d\n", &saidaX, &saidaY);

        ///carregando labirinto-------------------------
        char buffer[200];
        int i = 0, j, z;

        while(fscanf(file, "%[^\n]\n", buffer) != EOF)
        {
            j = 0;
            z = 0;

            while(buffer[z] != '\0')
            {
                if(buffer[z] != ';')
                {
                    maze->matriz[i][j].dado = buffer[z];
                    maze->matriz[i][j].x = 0;
                    maze->matriz[i][j].y = 0;
                    maze->matriz[i][j].rastro = -1;
                    j++;
                }
                z++;
            }
            i++;
        }

        ///escrevendo elementos do jogo no labirinto
        maze->matriz[playerX][playerY].dado = 'X';
        maze->matriz[monstro1X][monstro1Y].dado = '1';
        maze->matriz[monstro2X][monstro2Y].dado = '2';
        maze->matriz[monstro3X][monstro3Y].dado = '3';
        maze->matriz[monstro4X][monstro4Y].dado = '4';
        maze->matriz[saidaX][saidaY].dado = 'S';

        fclose(file);
    }
}

void destroiMaze(Maze *maze)
{
    int i;

    //desaloca todos as linhas
    for(i = 0; i < maze->linhas; i++)
    {
        free(maze->matriz[i]);
        maze->matriz[i] = NULL;
    }

    //desaloca o vetor de vetores
    free(maze->matriz);
    maze->matriz = NULL;

    //desaloca o TAD do tipo Maze
    free(maze);
    maze = NULL;
}

void exibirLabirinto(Maze *maze)
{
    int i, j;

    for(i = 0; i < maze->linhas; i++)
    {
        for(j = 0; j < maze->colunas; j++)
        {
            printf("%2c ",maze->matriz[i][j].dado);
        }
        printf("\n");
    }
}
