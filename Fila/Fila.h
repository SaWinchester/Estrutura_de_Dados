#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef long tipo_chave;

typedef struct{
    tipo_chave chave;
}tipo_elemento;

typedef struct nodo{
    struct nodo *prox;
    tipo_elemento info;
}tipo_nodo;

typedef struct{
    tipo_nodo *inicio, *fim;
    int tamanho;
}tipo_fila;

typedef tipo_fila *Fila;

Fila cria_fila();
int enfileirar(Fila fila, tipo_elemento elemento);
int desenfileirar(Fila fila, tipo_elemento *elemento);
int fila_vazia(Fila fila);
void destroi_fila(Fila fila);
void exibe_fila(Fila fila);

#endif // FILA_H_INCLUDED
