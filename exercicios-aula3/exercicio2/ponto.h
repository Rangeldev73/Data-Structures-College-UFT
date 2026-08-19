#ifndef PONTO_H
#define PONTO_H

typedef struct _ponto Ponto;
/*
cria instancias de um ponto.
@param float x
@param float y
@return Ponto*/
Ponto* Ponto_create(float,float);
/*
Imprime um ponto formatado com ate duas casas.
@param Ponto
@return void**/
void Ponto_print(Ponto*);
/*
Deleta instancias de ponto
@param Ponto
*/
void Ponto_delete(Ponto*);
/*
Copia os valores das variáveis para variáveis float passadas por parâmetro
@param ponto
@param x
@param y
*/
void Ponto_copia(Ponto*,float*,float*);
/*
Modifica os valores de x e y passagem por cópia
@param ponto
@param x
@param y*/
void Ponto_modifica(Ponto*,float,float);
/*
Calcula a distância euclidiana entre dois pontos
@param ponto
@param ponto
@return float
*/
float Pontos_distancia(Ponto*,Ponto*);
#endif