#include <stdio.h>

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

void bubbleRecursivo(int tam, int* vet) {
    int temp, fim = tam - 1, OK = 0; 
    for (int i = 0; i < fim; i++) {
        if (vet[i] > vet[i + 1]) {
            OK = 1;
            temp = vet[i + 1];
            vet[i + 1] = vet[i];
            vet[i] = temp;
        }
    }
    imprime(10, vet);
    // se uma troca foi realizada, a função é chamada novamente
    // tamanho do vetor REDUZIDO (sem os elementos ordenados)
    if (OK) bubbleRecursivo(tam - 1, vet); 
}

int main (void) {
    int lista[10] = {2, 3, 1, 4, 7, 5, 6, 9, 0, 8};
    printf("Vetor nao ordenado:\n");
    imprime(10, lista);
    bubbleRecursivo(10, lista);
    printf("Vetor ordenado:\n");
    imprime(10, lista);
    return 0;
}