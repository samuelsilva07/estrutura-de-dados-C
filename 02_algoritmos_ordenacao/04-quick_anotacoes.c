#include <stdio.h>  

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

void quick(int tam, int* vet) {
    if (tam > 1) { // verifica se o vetor tem tamanho 1 (não é necessário ordenar)
        int pivo = vet[0];
        int a = 1, b = tam - 1;
        do {
            while (a < tam && vet[a] <= pivo) a++;  // procura elemento maior que o pivô (início ao fim do vetor)
            while (vet[b] > pivo) b--;  // procura elemento menor que o pivô (fim ao início)
            printf("a = %d | b = %d\n", a, b);
            if (a < b) { // troca dos elementos (bolha)
                int temp = vet[a];
                vet[a] = vet[b];
                vet[b] = temp;
                a++; b--;   // continua a percorrer o vetor
                imprime(tam, vet);
                printf("a = %d | b = %d\n", a, b);
            }
        } while (a <= b); // enquanto o local de a seja menor ou igual ao de b (inversão)
        vet[0] = vet[b];
        vet[b] = pivo; // troca do elemento menor que o pivô com o pivô
        
        quick(b, vet); // ordena subvetor 1 (anterior ao pivô)
        quick(tam - a, &vet[a]); // ordena subvetor 2 (após o pivô)
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