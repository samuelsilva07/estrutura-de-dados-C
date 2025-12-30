#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FATORMULT 0.62457513781
// #define FATORDIVISAO 0x7FFFFFFF

/* https://youtube.com/playlist?list=PL8iN9FQ7_jt7GZiYfxGIb7sZJOQhw3Xr7&si=jUXMDvFsOwwiImVA */

typedef struct _hash_ {
    int quantidade;
    int tamanho;
    void** info; // "vetor" de ponteiros para os dados armazenados
} HASH;

typedef struct _dados_ {
    int matricula;
    char turma;
    char nome[41];
    char email[81];
} DADOS;

/* FUNÇÕES DE HASHING */

int hashing(int tamanho, int chave) {
    /* utiliza números aleatórios para a aplicação da fórmula 
        - 0 < num1 <= primo
        - 0 <= num2 <= primo
    */    
    int primo = 23;
    int num1 = rand() % (primo + 1);
    int num2 = rand() % primo;
    return ((num1 * chave + num2) % primo) % tamanho;
}

int hashingDobra(int tamanho, int chave) {
    // números tratados na forma binária!!
    int numBits = 10;
    int metade1 = chave >> numBits; // primeira metade da chave
    int metade2 = chave & (tamanho - 1); // segunda metade da chave
    return (metade1 ^ metade2); // soma as duas metades (através da operação or exculsivo)
}

int hashingMult(int tamanho, int chave) {
    chave = chave * FATORMULT; // produto da chave com a constante de multiplicação (que está entre 0 e 1)
    int valor = chave - (int) chave; // valor recebe apenas a parte fracionária do produto
    return (int) (valor * tamanho); // valor é multiplicado com o tamanho da tabela 
}

int chaveDivisao(int tamanho, int chave) {
    // divisão da chave (sem o sinal) pelo tamanho da tabela
    return ((unsigned int) chave) / tamanho;   
}

/* FUNÇÕES DE TRATAMENTO DE COLISÕES */

int duploHash(int H1, int posicao, int tamanho) {
    // utiliza duas funções de hashing para o cálculo da nova posição
    int H2 = hashingMult(tamanho, posicao) + 1;
    return H1 * posicao + H2;
}

int sondagemQuadratica(int posicao, int i, int tamanho) {
    // utiliza uma função do segundo grau para o cálculo da nova posicao
    posicao = posicao + 2*i + 5*i*i;
    return ((unsigned int) posicao) % tamanho;
}

int sondagemLinear(int posicao, int tamanho) {
    return ((unsigned int) posicao + 1) % tamanho;
}

/* FUNÇÕES COM TRATAMENTO DE COLISÃO */

DADOS* hashBusca(HASH* hash, int chave) {
    if (hash != NULL || hash->quantidade != hash->tamanho) {
        int posicao = hashing(hash->tamanho, chave);
        for (int i = 0; i < hash->tamanho; i++) {
            if (hash->info[posicao] != NULL) {
                return (DADOS*) hash->info;
            }
            posicao = duploHash(posicao, i, hash->tamanho);
        }
    }
    else printf("Falha na busca.\n");
    return NULL;
}

HASH* hashInsere(HASH* hash, int chave, DADOS* dados) {
    if (hash != NULL || hash->quantidade != hash->tamanho) {
        int posicao = hashing(hash->tamanho, chave);
        DADOS* novo = (DADOS*) malloc(sizeof(DADOS));
        if (novo != NULL) {
            for (int i = 0; i < hash->tamanho; i++) {
                if (hash->info[posicao] == NULL) {
                    novo = dados;
                    hash->info[posicao] = (void*) novo;
                    hash->quantidade++;
                    break; 
                }
                posicao = duploHash(posicao, i, hash->tamanho);
            }
        }
        else printf("Memoria indisponivel para inserir novos elementos.\n");
    }
    else printf("Falha na insercao.\n");
    return hash;
}

/* FUNÇÕES BASE (HASH) */

void liberaHash(HASH* hash) {
    if (hash != NULL) {
        for (int i = 0; i < hash->tamanho; i++)
            if (hash->info[i] != NULL) free(hash->info[i]); // libera os endereços
        free(hash->info); // libera o "vetor" da tabela
        free(hash); // libera o espaço ocupado pela tabela
    }
}

DADOS* hashBuscaSemColisao(HASH* hash, int chave) {
    if (hash != NULL) {
        int posicao = hashing(hash->tamanho, chave);
        // se a posição não estiver vazia, os dados da mesma são retornados pela função
        if (hash->info[posicao] != NULL) 
            return (DADOS*) hash->info[posicao];
        printf("A posicao esta vazia.\n");
    }
    else printf("Falha na busca.\n");
    return NULL;
}

HASH* hashInsereSemColisao(HASH* hash, int chave, DADOS* dados) {
    if (hash != NULL || hash->quantidade != hash->tamanho) {
        int posicao = hashing(hash->tamanho, chave); // indice do novo elemento na tabela
        DADOS* novo = (DADOS*) malloc(sizeof(DADOS));
        if (novo != NULL) {
            // se a posição estiver vazia, o elemento é inserido
            if (hash->info[posicao] == NULL) { 
                novo = dados;
                hash->info[posicao] = (void*) novo;
                hash->quantidade++;
            }
            else printf("Nao foi possivel inserir os dados.\n");
        }
        else printf("Memoria indisponível para inserir novos elementos.\n");
    }
    else printf("Falha na insercao.\n");
    return hash;
}

HASH* criaHash(int tamanhoTabela) {
    HASH* hash = (HASH*) malloc(sizeof(HASH));
    if (hash != NULL) {
        hash->tamanho = tamanhoTabela;
        hash->quantidade = 0; // inicia com nenhum elemento
        hash->info = (void**) calloc((size_t)tamanhoTabela, sizeof(void*)); // alocação dos "vetores" de endereços (calloc para zerar os espaços de memória)
        if (hash->info == NULL) { // caso em que não foi possível alocar memória
            free(hash);
            return NULL;
        }

        return hash;
    }
    printf("Nao foi possivel criar a hash.\n");
    return NULL;
}

/* FUNÇÕES PARA O EXEMPLO */

void imprimeAlunos(HASH* tabela) {
    DADOS* dados; 
    printf("------------------------------------\nALUNOS:\n");
    for (int i = 0; i < tabela->tamanho; i++) {
        if (tabela->info[i] != NULL) {
            dados = (DADOS*) tabela->info[i];
            printf("\nNome: %s\n", dados->nome);
            printf("Email: %s\n", dados->email);
            printf("Turma: %c\n", dados->turma);
            printf("Matricula: %d\n", dados->matricula);
        }
    }
}

DADOS* alocaAluno(char* nome, char* email, char turma, int matricula) {
    DADOS* novo = (DADOS*) malloc(sizeof(DADOS));
    strcpy(novo->nome, nome);
    strcpy(novo->email, email);
    novo->turma = turma;
    novo->matricula = matricula;

    return novo;
}

int main () {
    // aplicação de hash com a inserção de alunos, utilizando o numero da matricula como chave para as operações
    srand(time(NULL));
    int tamanhoTabela = 17;
    HASH* tabelaAlunos = criaHash(tamanhoTabela);
    DADOS* dadosAluno;
    int matricula;
    char turma, nome[41], email[81];
    int quantidadeAlunos;
    printf("Digite a quantidade de alunos que serao adicionados: ");
    scanf("%d", &quantidadeAlunos);
    for (int i = 0; i < quantidadeAlunos; i++) {
        printf("\nAluno %d:\n\n", i + 1);
        printf("Nome: ");
        scanf("%s", nome);
        printf("Email: ");
        scanf("%s", email);
        getchar();
        printf("Turma: ");
        scanf("%c", &turma);
        printf("Matricula: ");
        scanf("%d", &matricula);
        dadosAluno = alocaAluno(nome, email, turma, matricula);
        tabelaAlunos = hashInsere(tabelaAlunos, dadosAluno->matricula, dadosAluno);
    }
    imprimeAlunos(tabelaAlunos);
    liberaHash(tabelaAlunos); 
    exit(EXIT_SUCCESS);
}