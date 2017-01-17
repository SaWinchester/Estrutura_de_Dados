#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main()
{
    Pilha p = cria_pilha();
    exibe_pilha(p);

    tipo_elemento e;

    e.chave = 1234534535;
    push(p,e);
    exibe_pilha(p);

    e.chave = 34534535;
    push(p,e);
    exibe_pilha(p);

    e.chave = 1238534535;
    push(p,e);
    exibe_pilha(p);

    e.chave = 123432535;
    push(p,e);
    exibe_pilha(p);

    e.chave = 14535;
    push(p,e);
    exibe_pilha(p);

    pop(p,&e);
    exibe_pilha(p);

    pop(p,&e);
    exibe_pilha(p);

    termina_pilha(p);
    return 0;
}
