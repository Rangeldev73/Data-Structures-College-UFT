#ifndef RAC_H
#define RAC_H

typedef struct _rac Rac;
/*
Cria racional
@param int n
@param int d
*/
Rac* create(int, int);
/*
Soma dois números racionais
@param Rac
@param Rac
*/
Rac* soma(Rac*, Rac*);
/*
Multiplica dois números racionais
@param Rac
@param Rac
*/
Rac* multiplica(Rac*, Rac*);
/*
Testa se são iguais.
@param Rac
@param Rac
*/
int iguais(Rac*, Rac*);
#endif