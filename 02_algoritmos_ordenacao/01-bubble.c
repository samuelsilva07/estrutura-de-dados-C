#include <stdio.h>

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

void bubble(int tam, int* vet) {
    int temp, fim = tam - 1, OK = 0;
    do {
        OK = 0; // indica se houve troca no vetor
        for (int i = 0; i < fim; i++) { 
            if (vet[i] > vet[i + 1]) {
                OK = 1;                 
                // Bolha - troca dos elementos:  
                temp = vet[i + 1];
                vet[i + 1] = vet[i];
                vet[i] = temp;
            }
        }
        fim--;    // diminui o tamanho do vetor, pois o elemento na posição [fim] já está ordenado
    } while (OK); // loop se encerra quando nenhuma troca for realizada
}

int main (void) {
    int lista[10] = {2, 3, 1, 4, 7, 5, 6, 9, 0, 8};
    printf("Vetor nao ordenado:\n");
    imprime(10, lista);
    bubble(10, lista);
    printf("Vetor ordenado:\n");
    imprime(10, lista);
    return 0;
}