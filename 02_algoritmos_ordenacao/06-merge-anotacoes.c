#include <stdio.h>
#include <stdlib.h>

void imprime (int tam, int* vet) {
    for (int i = 0; i < tam; i++) 
        printf("%d ", vet[i]);
    printf("\n");
}

void intercala(int inicio, int meio, int tam, int *vet) {
    int i = inicio, j = meio, k = 0;
    int *vetTemp = malloc((tam - inicio) * sizeof(int)); // vetor com o tamanho da parte a ser ordenada 
    if (vetTemp == NULL) {
        printf("Memoria indisponivel para alocar o vetor!\n");
        exit(EXIT_FAILURE);
    }

    // adiciona os valores de forma ordenada no vetor (enquanto uma das condições não falhar)
    while (i < meio && j < tam) { 
        if (vet[i] <= vet[j]) vetTemp[k++] = vet[i++]; 
        else vetTemp[k++] = vet[j++];
    }

    // adiciona os valores que não foram ordenados em vetTemp 
    // obs: um desses loops NÂO VAI OCORRER, pois já foi realizado na etapa anterior
    while(i < meio) vetTemp[k++] = vet[i++];
    while(j < tam) vetTemp[k++] = vet[j++];

    // copia vetTemp para o vetor original (na metade correta - começando do local em inicio)
    for (i = inicio; i < tam; i++)
         vet[i] = vetTemp[i - inicio];
    // posição inicio de vet = posição 0 de vetTemp
    imprime(7, vet);
    free(vetTemp); // libera a memória utilizada na alocação
}

void merge(int inicio, int tam, int* vet) {
     if (inicio < tam - 1) {
        int meio = (int) (inicio + tam) / 2;
        merge(inicio, meio, vet); // primeira metade
        merge(meio, tam, vet);    // seguinda metade
        intercala(inicio, meio, tam, vet);  // "mescla" os vetores
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