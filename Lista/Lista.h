#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX 100

typedef long tipo_chave;

typedef struct{
    tipo_chave chave;
}tipo_elemento;

typedef struct nodo{
    tipo_elemento info;
    struct nodo *prox;
}tipo_nodo;

typedef struct{
    tipo_nodo *inicio;
    int tamanho;
}tipo_lista;

typedef tipo_lista *Lista;

Lista cria_lista();
int insere_lista_inicio(Lista lista, tipo_elemento elemento);
int insere_lista_fim(Lista lista, tipo_elemento elemento);
int insere_lista_posicao(Lista lista, tipo_elemento elemento, int posicao);
int remove_lista_inicio(Lista lista, tipo_elemento* elemento);
int remove_lista_final(Lista lista, tipo_elemento* elemento);
int remove_lista_posicao(Lista lista, tipo_elemento* elemento, int posicao);
int lista_vazia(Lista lista);
void termina_lista(Lista lista);
void exibe_lista(Lista lista);


#endif // LISTA_H_INCLUDED
