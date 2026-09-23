#ifndef TRANSB_H
#define TRANSB_H

#include <stdbool.h>

// Struct para representar cada transferencia PixED
typedef struct {
    int id_orig;
    int id_dest;
    float valor;
} PixED;

// Tipo opaco para a Fila/Buffer de Transacoes
typedef struct _trans Trans;

/**
 * Cria a fila com capacidade para v elementos.
 */
Trans* Trans_create(unsigned int v);

/**
 * Libera a memoria alocada para a fila.
 */
void Trans_destroy(Trans* f);

/**
 * Checa se a fila esta vazia.
 */
bool Trans_empty(Trans* f);

/**
 * Checa se a fila esta cheia.
 */
bool Trans_full(Trans* f);

/**
 * Insere um elemento PixED na fila.
 */
bool Trans_enqueue(Trans* f, PixED p);

/**
 * Remove um elemento PixED da fila.
 */
bool Trans_dequeue(Trans* f, PixED* p);

/** 
 * Retorna a quantidade atual de elementos na fila.
 */
unsigned int getSize(Trans* f);

/**
 * Esvazia a fila executando/imprimindo todas as transacoes pendentes.
 */
void Trans_process(Trans* f);

#endif