#include <stdio.h>

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

void insertion(int tam, int* vet) {
    for (int i = 1; i < tam; i++) { // loop vai "aumentando" o tamanho do vetor a ser tratado
        int j = i;  // j recebe o valor do fim do "sub-vetor"
        while (j > 0 && vet[j - 1] > vet[j]) {
            int temp = vet[i];
            vet[i] = vet[i - 1];
            vet[i - 1] = temp;
            j--;  // elementos são comparados na ordem INVERSA
        } 
    }
}

int main (void) {
    int lista[10] = {2, 3, 1, 4, 7, 5, 6, 9, 0, 8};
    printf("Vetor nao ordenado:\n");
    imprime(10, lista);
    insertion(10, lista);
    printf("Vetor ordenado:\n");
    imprime(10, lista);
    return 0;
}