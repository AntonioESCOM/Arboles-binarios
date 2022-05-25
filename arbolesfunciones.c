#include "arbolesfunciones.h"



int menuExtLib(){
	 int i;
  printf("1. Encontrar el numero de nodos\n2. Encontrar el numero de Hojas\n3. Encontrar la suma de los nodos totales\n4. Encontrar la suma de los nodos hoja\n5. Encontrar numero de nodos internos\n6. Suma de nodos internos\n7. Obtener el nodo menor\n8. Obtener el nodo mayor\n");
	printf("9. Dado un numero obtener el numero de nodos mayores\n10. Dado un numero obtener el numero de nodos menores\n11. Dado un numero obtener la suna  de nodos mayores\n12. Dado un numero obtener la suma de nodos menores\n13. Pertenece al arbol\n");
	printf("15.Eliminar el nodo menor del arbol\n16.Eliminar nodo\n17.Obtener la impresion de los nodos mayores a un numero\n18.Obtener la impresion de los nodos menores a un numero\nQue desea hacer?\n");
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
		if( (*ptrRaiz)->hijo_izq == NULL &&  (*ptrRaiz)->hijo_der == NULL ){
			return 1;
		}
		else{
			return numHojas(&(*ptrRaiz)->hijo_izq)+numHojas(&(*ptrRaiz)->hijo_der);
		}
}

int sumNodosHoja(struct nodo **ptrRaiz){
		if(*ptrRaiz == NULL)
			return 0;
		if( (*ptrRaiz)->hijo_izq == NULL &&  (*ptrRaiz)->hijo_der == NULL ){
			return (*ptrRaiz)->dato ;
		}
		else{
			return sumNodosHoja(&(*ptrRaiz)->hijo_izq)+sumNodosHoja(&(*ptrRaiz)->hijo_der);
		}
}



int sumNodosT(struct nodo **ptrRaiz){
	if(*ptrRaiz == NULL)
		return 0;
	else
		return sumNodosT(&((*ptrRaiz)->hijo_izq))+sumNodosT(&((*ptrRaiz)->hijo_der))+(*ptrRaiz)->dato;
	
}

int numNodosIn(struct nodo **ptrRaiz){
	if(*ptrRaiz == NULL)
		return 0;	
	if( (*ptrRaiz)->hijo_izq == NULL &&  (*ptrRaiz)->hijo_der == NULL )
		return 0;
	else
		return 1+numNodosIn(&(*ptrRaiz)->hijo_izq)+ numNodosIn(&(*ptrRaiz)->hijo_der);
	
}

int sumNodosIn(struct nodo **ptrRaiz){
		if(*ptrRaiz == NULL)
		return 0;	
	if( (*ptrRaiz)->hijo_izq == NULL &&  (*ptrRaiz)->hijo_der == NULL )
		return 0;
	else
		return (*ptrRaiz)->dato +sumNodosIn(&(*ptrRaiz)->hijo_izq)+ sumNodosIn(&(*ptrRaiz)->hijo_der);
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

/* Punto 9*/
int numNodosMayoresaux(struct nodo **ptrRaiz){
	if((*ptrRaiz)==NULL)
		return 0;
	else
		return numNodosMayoresaux(&((*ptrRaiz)->hijo_der))+1;
	
}

int numNodosMayores(struct nodo **ptrRaiz,int num){
	if(*ptrRaiz ==NULL)
		return 0;
	else if((*ptrRaiz)->dato ==num){
		return numNodosMayoresaux	(&((*ptrRaiz)->hijo_der));
	}
	else{
		return numNodosMayores(&((*ptrRaiz)->hijo_der),num)+numNodosMayores(&((*ptrRaiz)->hijo_izq),num);
	}
}

/* Punto 10*/

int numNodosMenoresaux(struct nodo **ptrRaiz){
	if((*ptrRaiz)==NULL)
		return 0;
	else
		return numNodosMenoresaux(&((*ptrRaiz)->hijo_izq))+1;
	
}

int numNodosMenores(struct nodo **ptrRaiz,int num){
	if(*ptrRaiz ==NULL)
		return 0;
	else if((*ptrRaiz)->dato == num){
		return numNodosMenoresaux	(&((*ptrRaiz)->hijo_izq));
	}
	else{
		return numNodosMenores(&((*ptrRaiz)->hijo_der),num)+numNodosMenores(&((*ptrRaiz)->hijo_izq),num);
	}
}

/* Punto 11 */
int numNodosMayoresSumAux(struct nodo **ptrRaiz){
	if((*ptrRaiz)==NULL)
		return 0;
	else
		return numNodosMayoresSumAux(&((*ptrRaiz)->hijo_der))+(*ptrRaiz)->dato;
	
}

int numNodosMayoresSum(struct nodo **ptrRaiz,int num){
	if(*ptrRaiz ==NULL)
		return 0;
	else if((*ptrRaiz)->dato ==num){
		return numNodosMayoresSumAux(&((*ptrRaiz)->hijo_der));
	}
	else{
		return numNodosMayoresSum(&((*ptrRaiz)->hijo_der),num)+numNodosMayoresSum(&((*ptrRaiz)->hijo_izq),num);
	}
}

/* Punto 12 */
int numNodosMenoresSumAux(struct nodo **ptrRaiz){
	if((*ptrRaiz)==NULL)
		return 0;
	else
		return numNodosMenoresSumAux(&((*ptrRaiz)->hijo_izq))+(*ptrRaiz)->dato;
	
}

int numNodosMenoresSum(struct nodo **ptrRaiz,int num){
	if(*ptrRaiz ==NULL)
		return 0;
	else if((*ptrRaiz)->dato ==num){
		return numNodosMenoresSumAux(&((*ptrRaiz)->hijo_izq));
	}
	else{
		return numNodosMenoresSum(&((*ptrRaiz)->hijo_der),num)+numNodosMenoresSum(&((*ptrRaiz)->hijo_izq),num);
	}
}

int miembro(struct nodo**ptrRaiz, int numSearch){
	if(*ptrRaiz ==NULL)
		return 0;
	else if((*ptrRaiz)->dato == numSearch)
		return 1;
	else if(numSearch<(*ptrRaiz)->dato)
		return miembro(&(*ptrRaiz)->hijo_izq,numSearch);
	else 
		return miembro(&(*ptrRaiz)->hijo_der,numSearch);
}


int eliminarMin(struct nodo **ptrRaiz){
	int suprimeMin=0;
	if((*ptrRaiz)->hijo_izq == NULL){
		suprimeMin=(*ptrRaiz)->dato;
		(*ptrRaiz)=(*ptrRaiz)->hijo_der;
	}
	else
		suprimeMin=eliminarMin(&(*ptrRaiz)->hijo_izq);
	
	return suprimeMin;
}

void eliminar(struct nodo** ptrRaiz,int numelim){
	if((*ptrRaiz) != NULL){
		if(numelim < (*ptrRaiz)->dato)
			return eliminar(&(*ptrRaiz)->hijo_izq,numelim);
		else if (numelim > (*ptrRaiz)->dato)
			return eliminar(&(*ptrRaiz)->hijo_der,numelim);
		else if((*ptrRaiz)->hijo_izq == NULL &&  (*ptrRaiz)->hijo_der == NULL)
			(*ptrRaiz)=NULL;
		else if((*ptrRaiz)->hijo_izq == NULL)
			(*ptrRaiz)=(*ptrRaiz)->hijo_der;
		else if((*ptrRaiz)->hijo_der == NULL)
			(*ptrRaiz)=(*ptrRaiz)->hijo_izq;
		else 
			(*ptrRaiz)->dato=eliminarMin(&(*ptrRaiz)->hijo_der);
	}
	return;
}

/* Punto 13 */
void impresionMayoresAux(struct nodo **ptrRaiz){
	if((*ptrRaiz)->hijo_der == NULL)
		return;
	else{
		printf("%d\n",(*ptrRaiz)->hijo_der->dato);
		impresionMayoresAux(&(*ptrRaiz)->hijo_der);
		}
		return;
}

void impresionMayores(struct nodo **ptrRaiz, int num){
	if(*ptrRaiz != NULL){
		if(num < (*ptrRaiz)->dato)
			return impresionMayores(&(*ptrRaiz)->hijo_izq,num);
		else if (num > (*ptrRaiz)->dato)
			return impresionMayores(&(*ptrRaiz)->hijo_der,num);
		else 
			impresionMayoresAux(&(*ptrRaiz));
	}
	return;
}

/* Punto 14 */
void impresionMenoresAux(struct nodo **ptrRaiz){
	if((*ptrRaiz)->hijo_izq == NULL)
		return;
	else{
		printf("%d\n",(*ptrRaiz)->hijo_izq->dato);
		impresionMenoresAux(&(*ptrRaiz)->hijo_izq);
	}
		return;
}

void impresionMenores(struct nodo **ptrRaiz, int num){
	if(*ptrRaiz != NULL){
		if(num < (*ptrRaiz)->dato)
			return impresionMenores(&(*ptrRaiz)->hijo_izq,num);
		else if (num > (*ptrRaiz)->dato)
			return impresionMenores(&(*ptrRaiz)->hijo_der,num);
		else 
			impresionMenoresAux(&(*ptrRaiz));
	}
	return;
}
