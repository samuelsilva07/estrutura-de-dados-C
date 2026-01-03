#include <stdio.h>
#include <stdlib.h>

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

void intercala(int inicio, int meio, int fim, int* vet) {
    int i = inicio, j = meio, k = 0;
    int* vetTemp = (int*) malloc((fim - inicio)*sizeof(int));

    while (i < meio && j < fim) {
        if (vet[i] <= vet[j]) vetTemp[k++] = vet[i++];
        else vetTemp[k++] = vet[j++];
    }
    
    while (i < meio) vetTemp[k++] = vet[i++];
    while (j < fim) vetTemp[k++] = vet[j++]; 

    for (i = inicio; i < fim; i++) vet[i] = vetTemp[i - inicio];
    free(vetTemp);
}

void merge(int inicio, int tam, int* vet) {
    if (inicio < tam - 1) {
        int meio = (int) (inicio + tam) / 2;
        merge(inicio, meio, vet);
        merge(meio, tam, vet);
        intercala(inicio, meio, tam, vet);
    }
}

int main (void) {
    int lista[7] = {38, 27, 43, 3, 9, 82, 10};
    printf("Vetor nao ordenado:\n");
    imprime(7, lista);
    merge(0, 7, lista);
    printf("Vetor ordenado:\n");
    imprime(7, lista);
    return 0;
}