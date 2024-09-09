#include "pilha_sequencial.h"
#include <stdlib.h>

struct pilha{
    ITEM* item[TAM];
    int tamanho;
};

bool pilha_empilhar(PILHA* pilha, ITEM* item){
    if(!pilha_cheia){
        pilha->item[pilha->tamanho] = item;
        pilha->tamanho++;

        return true;
    }

    return false;
}

ITEM* pilha_desempilhar(PILHA* pilha){
    ITEM* item = NULL;

    if(!pilha_vazia){  
        item = pilha->item[pilha->tamanho-1];
        pilha->tamanho--;
        pilha->item[pilha->tamanho] = NULL;
    }

    return item;
}

ITEM* pilha_topo(PILHA* pilha){
    if(!pilha_vazia){
        return pilha->item[pilha->tamanho-1];
    } else{
        return NULL;
    }
}

bool pilha_cheia(PILHA* pilha){
    if(pilha != NULL){
        return pilha->tamanho == TAM
            ? true
            : false;
    }

    return false;
}

bool pilha_vazia(PILHA* pilha){
    if(pilha != NULL){
        return pilha->tamanho == 0
            ? true
            : false;
    }

    return false;
}

PILHA* pilha_criar(void){
    PILHA* pilha;
    
    return pilha = (PILHA*) malloc(sizeof(PILHA));
}

bool pilha_apagar(PILHA** pilha){
    if(*pilha != NULL){
        free(*pilha);
        *pilha = NULL;

        return true;
    }

    return false;
}

int pilha_tamanho(PILHA* pilha){
    return pilha != NULL
        ? pilha->tamanho
        : -1;
}