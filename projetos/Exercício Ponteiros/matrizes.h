/******************************************************************************
 * DISCIPLINA: AEDs - I
 * AUTOR: Gustavo de Sousa Zimmermann
 *****************************************************************************/

#ifndef MATRIZES_H
#define MATRIZES_H

// Constante que define a dimensão das matrizes (linhas e colunas)
const int TAM = 128;

// Tipo personalizado para representar uma matriz de inteiros com dimensões TAM x TAM
typedef int Vetor[TAM][TAM];

void multiplicar_matriz(Vetor matriz, int escalar);

void transposta_matriz(Vetor resultado, const Vetor origem);

void inverter_colunas_matriz(Vetor matriz);

void inverter_linhas_matriz(Vetor matriz);

#endif