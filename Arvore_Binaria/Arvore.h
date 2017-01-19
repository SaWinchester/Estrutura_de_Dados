#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef int tipo_chave;

typedef struct{
    tipo_chave chave;
}tipo_elemento;

typedef struct nodo{
    struct nodo *direita, *esquerda;
    tipo_elemento info;
}tipo_nodo;

typedef tipo_nodo *Apontador;

Apontador cria_arvore();
int insere_arvore(Apontador *raiz,tipo_elemento elemento);
int insere_arvore_sem_recursao(Apontador *raiz,tipo_elemento elemento);
int exclui_arvore(Apontador *raiz,tipo_elemento *elemento);
int exclui_arvore_sem_recursao(Apontador *raiz,tipo_elemento *elemento);
Apontador minimo(Apontador raiz);
Apontador maximo(Apontador raiz);
void in_ordem(Apontador raiz);
void termina_arvore(Apontador raiz);
int altura(Apontador raiz);
int numero_nos(Apontador raiz);
int iguais(Apontador a, Apontador b);
#endif // ARVORE_H_INCLUDED
