#ifndef PILHA_H
    #define PILHA_H
    #define TAM 100
    #include "item.h"
    #include <stdbool.h>

    typedef struct pilha PILHA;

    // Funções principais
    bool pilha_empilhar(PILHA* pilha, ITEM* item);
    ITEM* pilha_desempilhar(PILHA* pilha);
    ITEM* pilha_topo(PILHA* pilha);
    bool pilha_cheia(PILHA* pilha);
    bool pilha_vazia(PILHA* pilha);

    // Funções secundárias
    PILHA* pilha_criar(void);
    void pilha_apagar(PILHA* pilha);
    int pilha_tamanho(PILHA* pilha);
#endif