#include <stdio.h>  

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

void quick(int tam, int* vet) {
    if (tam > 1) {
        int pivo = vet[0];
        int a = 1, b = tam - 1;

        do {
            while (a < tam && vet[a] <= pivo) a++;
            while (vet[b] >= pivo) b--;
            if (a < b) {
                int temp = vet[b];
                vet[b] = vet[a];
                vet[a] = temp;
                a++, b--;
            }
        } while (a <= b);
        vet[0] = vet[b];
        vet[b] = pivo;

        quick(b, vet);
        quick(tam - a, &vet[a]);
    }
}

int main (void) {
    int lista[10] = {2, 3, 1, 8, 7, 5, 6, 9, 0, 4};
    printf("Vetor nao ordenado:\n");
    imprime(10, lista);
    printf("\n");
    quick(10, lista);
    printf("Vetor ordenado:\n");
    imprime(10, lista);
    return 0;
}