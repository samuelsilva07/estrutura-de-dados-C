#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*  
Nesta biblioteca, uma outra abordagem de Max-Heap é utilizada:
   
    - utilizei um struct para a heap e outra para seus elementos - que conterão mais informações dentro de sua aplicação
    - para isso, a alocação de memória para a heap é essencial - pois ela auxilia no armazenamento e manutenção do fluxo de informações.
*/


struct Elemento {
    int prioridade; // prioridade do elemento, crucial para manter a ordem dos elementos na heap
    void* info;     // campo do tipo void, em que podemos utilizar QUALQUER TIPO DE DADOS!!! (desde que sejam manipulados corretamente)
    // obs: o campo info deve ser trabalhado com cuidado dentro de sua aplicação, para que não ocorram problemas na conversão de tipos ao armazenar os dados de um elemento  
}; 

struct Heap {
    int quantidade;                 // armazena a quantidade de elementos na heap, que varia com a inserção e a remoção de elementos
    ELEMENTO* vetor[TAMANHO_MAX];   // vetor da heap, com tamanho máximo de 127 elementos (definido no arquivo heap.h)
};


int divInt(int num1, int num2) { // retorna a divisão inteira do primeiro número pelo segundo
    return (int) num1 / num2;
}

void heapLibera(HEAP* h) {  // libera a memória ocupada pelo vetor da heap
    for (int i = 0; i < TAMANHO_MAX; i++) 
        if (h->vetor[i] != NULL) free(h->vetor[i]);
    free(h);
}

int heapVazia(HEAP* h) {    // retorna 1 se a heap estiver vazia - caso contrário, retorna 0
    return h->quantidade == 0;
}

int heapCheia(HEAP* h) {    // retorna 1 se a heap estiver cheia - caso contrário, retorna 0
    return h->quantidade < TAMANHO_MAX;
}

/*  Como o campo info é do tipo void*, a função de impressão da heap varia de acordo com a aplicação da biblioteca.
    Para criar a função, realize os seguintes passos:

        -

*/

ELEMENTO* heapRemove(HEAP* h) { // retorna o elemento do topo da heap e realiza a reordenação dos demais elementos para removê-lo da sequência
    if (!heapVazia(h)) {    // verifica se a heap não está vazia
        ELEMENTO* removido = h->vetor[0];   // elemento do topo, que será retornado ao fim da função
        int ultimo = h->quantidade - 1;
        ELEMENTO* elem = h->vetor[ultimo];  // último elemento da heap, que será reordenado no algoritmo a partir do topo
        int k = 0;  // posição do topo da heap

        /* 
        loop ocorre enquanto: 
            1 - o próximo elemento for menor que o tamanho da heap 
            2 - prioridade de elem for menor que a de seus filhos (2k+1 e 2k+2)
        */
        while ((2*k + 1 < ultimo) && (elem->prioridade < h->vetor[2*k + 1]->prioridade || elem->prioridade < h->vetor[2*k + 2]->prioridade)) {
            // inserção do lado esquerdo 
            if (h->vetor[2*k + 1]->prioridade > h->vetor[2*k + 2]->prioridade) {
                h->vetor[k] = h->vetor[2*k + 1];
                k = 2*k + 1;
            }
            // inserção do lado direito
            else {
                h->vetor[k] = h->vetor[2*k + 2];
                k = 2*k + 2;
            }
        }
        h->vetor[k] = elem; // insere elem na posição correta
        free(h->vetor[-1]); // libera a memória do elemento duplicado
        --h->quantidade;    // quantidade de elementos da heap diminui em uma unidade
        return removido;    // elemento removido é retornado
    }
    printf("A fila esta vazia!\n"); // imprime mensagem de erro e encerra a função
    return NULL;
}

void heapInsere(HEAP* heap, ELEMENTO* elem) { // insere um elemento no vetor da heap, na posição correspondente a sua prioridade
    if (heapCheia(heap)) { // verifica se a heap não está cheia
        heap->quantidade++; // quantidade de elementos da heap aumenta em uma unidade
        int k = heap->quantidade - 1;

        /* 
        loop ocorre enquanto:
            1 - a posição do elemento for maior que a inicial 
            2 - a prioridade do elemento for maior do que a de seu pai - no caso, divInt[(k, 2)]
        */
        while (k > 0 && (elem->prioridade > heap->vetor[divInt(k, 2)]->prioridade)) {
            heap->vetor[k] = heap->vetor[divInt(k, 2)]; // elemento assume o lugar de seu pai
            k = divInt(k, 2);   // valor de k é reajustado para a nova posição
        }
        heap->vetor[k] = elem; // insere elem na posição correta
        return;
    }
    printf("A fila esta cheia!\n"); // imprime mensagem de erro e encerra a função
}

HEAP* heapCria() { // aloca a memória necessária para a heap, e inicializa todo o vetor com NULL
    HEAP* h = (HEAP*) malloc(sizeof(HEAP));
    h->quantidade = 0;
    for (int i = 0; i < TAMANHO_MAX; i++) 
        h->vetor[i] = NULL;
    return h;
}