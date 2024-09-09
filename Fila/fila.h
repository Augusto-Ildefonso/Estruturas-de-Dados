#ifndef FILA_H
    #define FILA_H
    #include "item.h"
    #include <stdbool.h>

    #define TAM_MAX 100

    typedef struct fila_ FILA;

    FILA* fila_criar(void);
    bool fila_inserir(FILA* F, ITEM* item);
    ITEM* fila_remover(FILA* F);
    bool fila_vazia(FILA* F);
    bool fila_cheia(FILA* F);
    int fila_tamanho(FILA* F);
    ITEM* fila_frente(FILA* F);

#endif
