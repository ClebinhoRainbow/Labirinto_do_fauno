#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include "Position.h"

typedef struct
{
    int linhas;
    int colunas;
    Position **matriz;

}Maze;

/*
 * Cria o labirinto e a matriz de jogo em memória
 * Importante: os campos da matriz não são inicializados
 */
Maze * criarMaze(int linhas, int colunas);

/*
 * Inicializa o labirinto a partir de um arquivo de texto (carrega as informações para o campo dado)
 * O nome do arquivo deve ser passado como argumento para a função
 * Os demais campos de cada célula da matriz são inicializados da seguinte forma:
 * x = 0, y = 0 e rastro = -1
 */
void carregarDadosDoArquivo(Maze *maze, char * nomeArquivo);

/*
 * Libera a memória alocada para qualquer TAD do tipo Maze
 */
void destroiMaze(Maze *maze);

/*
 * Exibe o conteúdo do labirinto, somente o campo dado
 */
void exibirLabirinto(Maze *maze);

#endif // MAZE_H_INCLUDED
