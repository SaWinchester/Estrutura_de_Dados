#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"

void bubble_sort(int *vetor,int quantidade){
    int indice_pri, indice_sec, aux, qtd_sec;

    for(indice_pri = 0; indice_pri < quantidade; indice_pri++){
            qtd_sec = quantidade - (indice_pri+1);
        for(indice_sec = 0; indice_sec < qtd_sec; indice_sec++){

            if(vetor[indice_sec] > vetor[indice_sec+1]){
                aux = vetor[indice_sec];
                vetor[indice_sec] = vetor[indice_sec+1];
                vetor[indice_sec+1] = aux;
            }
        }
    }
}

void selection_sort(int *vetor, int quantidade){
    int indice_pri, indice_sec, aux, posicao_minimo;

    for(indice_pri = 0; indice_pri < quantidade-1;indice_pri++){
        posicao_minimo = indice_pri;
        for(indice_sec = (indice_pri+1); indice_sec < quantidade;indice_sec++)
            if(vetor[indice_sec] < vetor[posicao_minimo]) posicao_minimo = indice_sec;

        if(indice_pri != posicao_minimo){
            aux = vetor[indice_pri];
            vetor[indice_pri] = vetor[posicao_minimo];
            vetor[posicao_minimo] = aux;
        }

    }
}

void insertion_sort(int *vetor, int quantidade){
    int indice_pri, indice_sec, valor_atual;

    for(indice_pri = 1; indice_pri < quantidade; indice_pri++){
        valor_atual = vetor[indice_pri];
        indice_sec = indice_pri - 1;

        while(indice_sec >= 0 && vetor[indice_sec] > valor_atual){
            vetor[indice_sec+1] = vetor[indice_sec];
            indice_sec--;
        }

        vetor[indice_sec+1] = valor_atual;
    }
}

void merge_sort(int *vetor, int posicao_inicial, int posicao_final){
    int i, j, k, metade_vetor, *vetor_temp;

    if(posicao_inicial == posicao_final) return;

    metade_vetor = (posicao_inicial+posicao_final)/2;

    merge_sort(vetor,posicao_inicial,metade_vetor);
    merge_sort(vetor,metade_vetor+1,posicao_final);

    i = posicao_inicial;
    j = metade_vetor + 1;
    k = 0;

    vetor_temp = (int*) malloc(sizeof(posicao_final-posicao_inicial+1));

    while( i < metade_vetor + 1 || j < posicao_final + 1){
        if( i == metade_vetor + 1){
            vetor_temp[k] = vetor[j];
            j++;
            k++;
        }else{
            if( j == posicao_final + 1){
                vetor_temp[k] = vetor[i];
                i++;
                k++;
            }else{
                if( vetor[i] < vetor[j]){
                    vetor_temp[k] = vetor[i];
                    i++;
                    k++;
                }else{
                    vetor_temp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }
    }

    for( i = posicao_inicial; i <= posicao_final; i++) vetor[i] = vetor_temp[i-posicao_inicial];
}
