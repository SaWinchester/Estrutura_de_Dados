#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef long tipo_chave;

typedef struct{
    tipo_chave chave;
}tipo_elemento;

typedef struct nodo{
    struct nodo *prox, *ant;
    tipo_elemento info;
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
