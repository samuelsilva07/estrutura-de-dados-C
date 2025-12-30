#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
} ARV;

int arvPertence(char valor, ARV* arvore) {
    if (arvore == NULL) return 0;
    else return arvore->info == valor || arvPertence(valor, arvore->esq) || arvPertence(valor, arvore->esq);
}

void arvImprime(ARV* arvore) {
    if(arvore != NULL) {
        printf("<");
        printf("%c ", arvore->info);
        arvImprime(arvore->esq);
        arvImprime(arvore->dir);
        printf(">");
    }
}

ARV* arvLibera(ARV* arvore) {
    if (arvore != NULL) {
        arvLibera(arvore->esq);
        arvLibera(arvore->esq);
        free(arvore);
    }
    return NULL;
}

ARV* arvCria(char valor, ARV* arvEsq, ARV* arvDir) {
    ARV* p = (ARV*) malloc(sizeof(ARV));
    p->info = valor;
    p->esq = arvEsq;
    p->dir = arvDir;
    return p;
}

ARV* arvCriaVazia() {
    return NULL;
}

int main () {
    ARV* a = arvCriaVazia();
    a = arvCria('a', arvCriaVazia(), arvCriaVazia());
    arvImprime(a);
    printf("\n");
    a->esq = arvCria('b', arvCria('d', arvCriaVazia(), arvCriaVazia()), arvCria('e', arvCriaVazia(),arvCriaVazia()));
    a->dir = arvCria('c', arvCriaVazia(), arvCriaVazia());
    arvImprime(a);
    printf("\n");
    a->dir->esq = arvCria('f', arvCria('g', arvCriaVazia(), arvCriaVazia()), arvCria('h',arvCriaVazia(),arvCriaVazia())); 
    arvImprime(a);
    printf("\n");
    a = arvLibera(a);
    printf("Arvore liberada!\n");
    exit(EXIT_SUCCESS);
}