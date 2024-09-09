#include "fila.h"

struct fila_{
    ITEM* fila[TAM_MAX];
    int inicio;
    int fim;
    int tamanho;
};

FILA* fila_criar(void){
    FILA* F;
    F = (FILA*) malloc(sizeof(FILA));

    if(F != NULL){
        F->inicio = 0;
        F->fim = 0;
        F->tamanho = 0;
    } 
    
    return F;
}

bool fila_inserir(FILA* F, ITEM* item){
    if(!fila_cheia(F)){
        F->fila[F->fim] = item;
        F->tamanho++;

        /*
        Um jeito de resolver:

        F->fim++;
        if(F->fim == TAM_MAX){
            F->fim = 0;
        } 
        */

        // Outro jeito:
        F->fim = (F->fim + 1) % TAM_MAX;

        return true;
    }
    return false;
}

ITEM* fila_remover(FILA* F){
    if(!fila_vazia(F)){
        ITEM* item = F->fila[F->inicio];
        F->fila[F->inicio] = NULL;
        F->inicio = (F->inicio + 1) % TAM_MAX;
        F->tamanho--;
        return item;
    }
    return NULL;
}

bool fila_cheia(FILA* F){
    if(F != NULL){
        return F->tamanho == TAM_MAX;
    }

    return true;   
}

bool fila_vazia(FILA* F){
    if(F != NULL){
        return fila->tamanho == 0;
    }

    return true;
}

int fila_tamanho(FILA* F){
    return F->tamanho;
}

ITEM* fila_frente(FILA* F){
    return F->fila[F->inicio];
}
