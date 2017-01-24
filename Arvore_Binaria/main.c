#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main()
{
    Apontador p = cria_arvore();
    tipo_elemento e;

    e.chave = 40;
    insere_arvore(&p,e);

    e.chave = 54;
    insere_arvore(&p,e);

    e.chave = 42;
    insere_arvore(&p,e);

    e.chave = 34;
    insere_arvore(&p,e);

    e.chave = 1;
    insere_arvore(&p,e);

    e.chave = 25;
    insere_arvore(&p,e);

    e.chave = 21;
    insere_arvore(&p,e);

    e.chave = 29;
    insere_arvore(&p,e);

    e.chave = 20;
    insere_arvore(&p,e);

    e.chave = 12;
    insere_arvore(&p,e);

    e.chave = 13;
    insere_arvore(&p,e);

    in_ordem(p);

    printf("\n\nAltura = %d\n\n",altura(p));
    printf("\n\nNumero de Nos = %d\n\n",numero_nos(p));

    Apontador b = cria_arvore();
    e.chave = 40;
    insere_arvore(&b,e);

    e.chave = 54;
    insere_arvore(&b,e);

    e.chave = 42;
    insere_arvore(&b,e);

    e.chave = 34;
    insere_arvore(&b,e);

    e.chave = 1;
    insere_arvore(&b,e);

    e.chave = 25;
    insere_arvore(&b,e);

    e.chave = 21;
    insere_arvore(&b,e);

    e.chave = 29;
    insere_arvore(&b,e);

    e.chave = 20;
    insere_arvore(&b,e);

    e.chave = 12;
    insere_arvore(&b,e);

    e.chave = 13;
    insere_arvore(&b,e);

    e.chave = 25;
    exclui_arvore_sem_recursao(&b,&e);

    in_ordem(b);

    printf("\n%d\n",iguais(p,b));


    termina_arvore(p);
    return 0;
}
