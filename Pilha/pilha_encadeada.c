#include "pilha_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;

struct no{
    ITEM* item;
    NO* proximo;
};

struct pilha{
    NO* topo;
    int tamanho;
};

bool pilha_empilhar(PILHA* pilha, ITEM* item){
    NO* aux = NULL;
    if(pilha != NULL){
        aux->item =item;
        pilha->topo = aux;
        pilha->tamanho++;
        aux->proximo = NULL;

        return pilha; 
    }

    return NULL;
}

ITEM* pilha_desempilhar(PILHA* pilha){
    ITEM* item = NULL;
    NO* aux;
    if(!pilha_vazia(pilha)){
        item = pilha->topo->item;
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux->proximo);
        aux->proximo = NULL;
        pilha->tamanho--;
    }

    return item;
}

ITEM* pilha_topo(PILHA* pilha){
    ITEM* item = NULL;
    
    if(pilha != NULL){
        item = pilha->topo->item;    
    }

    return item;
}

bool pilha_vazia(PILHA* pilha){
    if(pilha != NULL){
        return pilha->tamanho == 0
            ? true
            : false;
    }

    return false;
}

bool pilha_cheia(PILHA* pilha){
    if(pilha != NULL){
        NO* no = (NO*) malloc(sizeof(NO));
        return no == NULL
            ? true
            : free(no), false;
    }
}

PILHA* pilha_criar(void){
    PILHA* pilha = (PILHA*) malloc(sizeof(PILHA));

    if(pilha != NULL){
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }

    return pilha;
}

void pilha_apagar(PILHA** pilha){
    ITEM* item;
    if(*pilha != NULL){
        while(!pilha_vazia(*pilha)){
            item = pilha_desempilhar(*pilha);
            item_apagar(item);
        }

    free(*pilha);
    *pilha = NULL;
    }
}

int pilha_tamanho(PILHA* pilha){
    return pilha->tamanho;
}