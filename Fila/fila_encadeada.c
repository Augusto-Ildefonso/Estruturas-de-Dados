#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;

struct no{
    ITEM *item;
    NO *proximo;
};

struct fila_{
    // Dois ponteiros pois eu retiro do fim e coloco no começo
    NO *inicio; 
    NO *fim;
    int tamanho;
};

FILA *fila_criar(void){
    FILA *fila = (FILA *) malloc(sizeof(FILA));
    fila->inicio = NULL;
    fila->fim = fila->inicio;
    fila->tamanho = 0;

    return fila;
}

bool fila_inserir(FILA* F, ITEM* item){
    if(!fila_cheia(F)){
        NO *no = (NO *) malloc(sizeof(NO));

        no->item = item;
        no->proximo = NULL;

        if(F->tamanho == 0){
            F->inicio = no;
        } else{
            F->fim->proximo = no;   
        }

        F->fim = no;
        F->tamanho++;

        return true;
    }

    return false; 
}

ITEM* fila_remover(FILA* F){
    if(!fila_vazia(F)){
        NO* no = F->inicio;
        ITEM* item = F->inicio->item;

        F->inicio = F->inicio->proximo;
        no->proximo = NULL;

        if(F->tamanho == 1){
            F->fim = NULL;
        }

        free(no);
        no = NULL;

        F->tamanho--;    
        
        return item;
    }

    return NULL;
}

bool fila_cheia(FILA* F){
    if(F != NULL){
        NO* no;
        if((no = (NO *) malloc(sizeof(NO))) != NULL){
            free(no);
            no = NULL;
            return false;
        } 

        return true;    
    }

    return true;
}

bool fila_vazia(FILA* F){
    if(F != NULL){
        return F->tamanho == 0;
    }

    return true;
}

int fila_tamanho(FILA* F){
    return F->tamanho;
}

ITEM* fila_frente(FILA* F){
    
}