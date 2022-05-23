#include "arbolesfunciones.h"



int menuExtLib(){
	 int i;
  printf("1. Encontrar el numero de nodos\n2. Encontrar el numero de Hojas\n3. Encontrar la suma de los nodos totales\n5. Encontrar numero de nodos internos\n7. Obtener el nodo menor\n8. Obtener el nodo mayor\n");
  printf("9. Dado un numero obtener el numero de nodos mayores\nQue desea hacer?\n");
	scanf("%d", &i);
  return i;
}

int numNodos(struct nodo **ptrRaiz){
	if(*ptrRaiz == NULL)
		return 0;
	else
		return 1+numNodos(&((*ptrRaiz)->hijo_izq))+numNodos(&((*ptrRaiz)->hijo_der));
}

int numHojas(struct nodo **ptrRaiz){
		if(*ptrRaiz == NULL)
			return 0;
		else if( (&(*ptrRaiz)->hijo_izq == NULL) &&  (&(*ptrRaiz)->hijo_der == NULL) ){
			return 1;
		}
		else{
			return numHojas(&(*ptrRaiz)->hijo_izq)+numHojas(&(*ptrRaiz)->hijo_der);
		}
}

int sumNodosT(struct nodo **ptrRaiz){
	if(*ptrRaiz == NULL)
		return 0;
	else
		return sumNodosT(&((*ptrRaiz)->hijo_izq))+sumNodosT(&((*ptrRaiz)->hijo_der))+(*ptrRaiz)->dato;
	
}

int numNodosIn(struct nodo **ptrRaiz){
	int aux=0;
	if(*ptrRaiz == NULL)
		return 0;
	else {
		if(&(*ptrRaiz)->hijo_izq != NULL ||  &(*ptrRaiz)->hijo_der != NULL )
			aux=1;
		else
			aux=0;
		return aux+numNodosIn(&(*ptrRaiz)->hijo_izq)+ numNodos(&(*ptrRaiz)->hijo_der);
	}

}

int getMinNod(struct nodo **ptrRaiz){
	if((*ptrRaiz)->hijo_izq ==NULL)
		return (*ptrRaiz)->dato;
	else{
		return getMinNod(&((*ptrRaiz)->hijo_izq));
	}
}
int getMaxNod(struct nodo **ptrRaiz){
	if((*ptrRaiz)->hijo_der ==NULL)
		return (*ptrRaiz)->dato;
	else
		return getMaxNod(&((*ptrRaiz)->hijo_der));
	
}

int numNodosMayores(struct nodo **ptrRaiz,int num){
	if(*ptrRaiz ==NULL)
		return 0;
	else if((*ptrRaiz)->dato ==num){
		return 1+numNodosMayores(&((*ptrRaiz)->hijo_der),num);
	}
	else{
		return numNodosMayores(&((*ptrRaiz)->hijo_der),num)+numNodosMayores(&((*ptrRaiz)->hijo_izq),num);
	}
	
	
}