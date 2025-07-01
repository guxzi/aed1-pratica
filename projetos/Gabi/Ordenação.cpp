#include <stdio.h>
#include "Ordena.h"

void escrevevetor(int* vetor, int tamanho) {
    if (vetor == nullptr) {
        return;
    }
    for (int i = 0; i < tamanho; ++i) {
       printf("%d ", *(vetor + i));
    }
}


/*
Exemplo de ordenação de vetor
utilizando Bubble Sort, Selection Sort e Insertion Sort.
*/

int main(){

// Exemplo de vetor a ser ordenado    
int vetor[] = {5, 2, 9, 1, 5, 6};

// Exibição do vetor original
printf("Vetor original:\n");
escrevevetor(vetor, 6);
printf("\n\n");

//Escolha do método de ordenação 
printf("Escolha o método de ordenação:\n");
printf("1. Bubble Sort\n");
printf("2. Selection Sort\n");
printf("3. Insertion Sort\n");
int escolha;
scanf("%d", &escolha);

switch (escolha)    
{
case 1:
    Bublesort(vetor, 6);
printf("Vetor ordenado com Bubble Sort:\n");
escrevevetor(vetor, 6);
printf("\n");
    break;

    case 2:
    selectionsort(vetor, 6);
printf("Vetor ordenado com Selection Sort:\n");
escrevevetor(vetor, 6);
printf("\n");
    break;

    case 3:
    insertsort(vetor, 6);
printf("Vetor ordenado com Insertion Sort:\n");
escrevevetor(vetor, 6);
printf("\n");
    break;

default:
    break;
}


return 0;
}