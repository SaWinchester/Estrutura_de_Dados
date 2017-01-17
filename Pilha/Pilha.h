#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef long tipo_chave;

typedef struct{
    tipo_chave chave;
}tipo_elemento;

typedef struct nodo{
    struct nodo *prox;
    tipo_elemento info;
}tipo_nodo;

typedef struct{
    tipo_nodo *topo;
    int tamanho;
}tipo_pilha;

typedef tipo_pilha *Pilha;

Pilha cria_pilha();
int push(Pilha pilha, tipo_elemento elemento);
int pop(Pilha pilha, tipo_elemento *elemento);
int pilha_vazia(Pilha pilha);
void termina_pilha(Pilha pilha);
void exibe_pilha(Pilha pilha);

#endif // PILHA_H_INCLUDED
