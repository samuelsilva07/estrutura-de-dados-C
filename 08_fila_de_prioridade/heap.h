#define TAMANHO_MAX 127

typedef struct Elemento ELEMENTO;
typedef struct Heap HEAP;

int divInt(int num1, int num2);
void heapLibera(HEAP* h);
int heapVazia(HEAP* h);
int heapCheia(HEAP* h);
ELEMENTO* heapRemove(HEAP* h);
void heapInsere(HEAP* h, ELEMENTO* elem);
HEAP* heapCria();