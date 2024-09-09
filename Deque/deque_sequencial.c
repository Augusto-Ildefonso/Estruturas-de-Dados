#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "Deque.h"

#define TAM_MAX 100

struct deque_{
    ITEM* deque[TAM_MAX];
    int inicio;
    int fim;
    int tamanho;
};

DEQUE* deque_criar(void){
    DEQUE* deque;

    deque = (DEQUE*) malloc(sizeof(DEQUE));
    
    if(deque != NULL){
        deque->inicio = 0;
        deque->fim = 0;
        deque->tamanho = 0;
    }

    return deque;    
}

void deque_apagar(DEQUE** deque){
    if(*deque != NULL){
        free(*deque);
        *deque = NULL;
    }
}

bool deque_inserir_inicio(DEQUE* deque, ITEM* item){
    if(!deque_cheia(deque)){
        if(deque->inicio == deque->fim){
            deque->deque[deque->inicio] = item;
            deque->fim++;
        } else{
            if(deque->inicio == 0){
                deque->inicio = TAM_MAX;
            } else{
                deque->inicio--;
            }
            deque->deque[deque->inicio] = item;            
        }

         deque->tamanho++;    

         return true;    
    }

    return false;
}

bool deque_inserir_fim(DEQUE* deque, ITEM* item){
    if(!deque_cheia(deque)){
        deque->deque[deque->fim] = item;
        if(deque->fim == TAM_MAX){
            deque->fim = 0;
        } else{
            deque->fim++;
        }
        deque->fim++;
        deque->tamanho++;    

        return true;    
    }

    return false;
}

ITEM* deque_remover_inicio(DEQUE* deque){
    if(!deque_vazia(deque)){
        ITEM* item;
        item = deque->deque[deque->inicio];
        if(deque->inicio == TAM_MAX){
            deque->inicio = 0;
        } else{
            deque->inicio++;
        }
        
        deque->tamanho--;

        return item;
    }

    return NULL;
}



ITEM* deque_remover_fim(DEQUE* deque){
    if(!deque_vazia(deque)){
        ITEM* item;
        item = deque->deque[deque->inicio];
        if(deque->fim == 0){
            deque->fim = TAM_MAX;
        } else{
            deque->fim--;
        }
        
        deque->tamanho--;

        return item;
    }

    return NULL;
}


ITEM* deque_primeiro(DEQUE* deque){
    return deque->deque[deque->inicio];
}

ITEM* deque_ultimo(DEQUE* deque){
    return deque->deque[deque->fim];
}

int deque_contar(DEQUE* deque){
    return deque->tamanho;
}

bool deque_vazia(DEQUE* deque){
    if(deque != NULL){
        return deque->tamanho;
    }

    return true;
}

bool deque_cheia(DEQUE* deque){
    if(deque != NULL){
        return deque->tamanho == TAM_MAX;
    }

    return true;
}