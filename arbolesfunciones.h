#ifndef _ARBOLESFUNCIONES_H
#define _ARBOLESFUNCIONES_H
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct nodo{
	int dato;
	struct nodo *hijo_izq;
	struct nodo *hijo_der;
};
int menuExtLib();
int numNodos(struct nodo **ptrRaiz); 
int numHojas(struct nodo **ptrRaiz);
int sumNodosT(struct nodo **ptrRaiz);
int sumNodosHoja(struct nodo **ptrRaiz);
int sumNodosIn(struct nodo **ptrRaiz);
int numNodosIn(struct nodo **ptrRaiz);
int getMinNod(struct nodo **ptrRaiz);
int getMaxNod(struct nodo **ptrRaiz);
int numNodosMayores(struct nodo **ptrRaiz,int num);
int numNodosMayoresaux(struct nodo **ptrRaiz);
int numNodosMenores(struct nodo **ptrRaiz,int num);
int numNodosMenoresaux(struct nodo **ptrRaiz);
int numNodosMayoresSumAux(struct nodo **ptrRaiz);
int numNodosMayoresSum(struct nodo **ptrRaiz,int num);
int numNodosMenoresSumAux(struct nodo **ptrRaiz);
int numNodosMenoresSum(struct nodo **ptrRaiz,int num);
int miembro(struct nodo**ptrRaiz, int numSearch);
void impresionMayores(struct nodo **ptrRaiz, int num);
void impresionMayoresAux(struct nodo **ptrRaiz);
void eliminar(struct nodo** ptrRaiz,int numelim);
int eliminarMin(struct nodo **ptrRaiz);
void impresionMenoresAux(struct nodo **ptrRaiz);
void impresionMenores(struct nodo **ptrRaiz, int num);


#endif