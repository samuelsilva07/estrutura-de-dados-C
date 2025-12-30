#include <stdio.h>

void imprimeVetor (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

int checaVetor(int tam, int* vet) { // verifica se o vetor está ordenado
    for (int i = 0; i < tam; i++)
        if (vet[i] > vet[i + 1]) return 0;
    return 1;
}

void troca (int* vet, int i) { // função que troca a posição de um elemento com seu sucessor 
    int temp = vet[i];
    vet[i] = vet[i + 1];
    vet[i + 1] = temp;
}

void bubbleRecursivo(int tam, int* vet) {
    int fim = tam - 1; 
    for (int i = 0; i < fim; i++) 
        if (vet[i] > vet[i + 1]) troca(vet, i);
    imprimeVetor(10, vet);
    // a recursão ocorre de acordo com o valor de checaVetor 
    if (!checaVetor(tam, vet)) bubbleRecursivo(tam - 1, vet);
}

int main (void) {
    int lista[10] = {2, 3, 1, 4, 7, 5, 6, 9, 0, 8};
    printf("Vetor nao ordenado:\n");
    imprimeVetor(10, lista);
    bubbleRecursivo(10, lista);
    printf("Vetor ordenado:\n");
    imprimeVetor(10, lista);
    return 0;
}