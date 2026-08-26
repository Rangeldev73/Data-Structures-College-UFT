#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct _conj Conj;
/*
Print de um conjunto
@param Conj*
*/
void conj_print(Conj*);
/*
Criação de um conjunto vazio;
*/
Conj* conj_create();
/*
Inserção de um elemento a um conjunto
@param Conj* 
@param v
*/
void conj_insert(Conj*, int);
/*
Remoção de um elemento do conjunto
@param Conj* 
@param v
*/
void conj_remove(Conj*, int);
/*
Interseção (deve receber dois conjuntos e criar um outro que represente a interseção);
@param Conj* 
@param Conj* 
*/
Conj* conj_intersection(Conj*,Conj*);
/*
Diferença entre dois conjuntos
@param Conj* 
@param Conj* 
*/
Conj* conj_difference(Conj*,Conj*);
/*
União entre dois conjuntos
@param Conj* 
@param Conj*
*/
Conj* conj_union(Conj*,Conj*);
/*
Maior valor
@param Conj*
*/
int getmaior(Conj*);
/*
menor valor
@param Conj*
*/
int getmenor(Conj*);
/*
Teste se dois conjuntos são iguais;
@param Conj* 
@param Conj*
*/
int conj_iguais(Conj*,Conj*);
/*
Tamanho do conjunto;
@param Conj*
*/
int conj_getsize(Conj*);
/*
Se o conjunto é vazio
@param Conj*
*/
int conj_empty(Conj*);
#endif