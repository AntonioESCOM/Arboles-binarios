
#include "arbolesfunciones.h"



int menu(){
  int i;
  printf("Que quiere hacer? \n 1. Guardar datos \n 2. Exhibir contenido\n 3. Imprimir en Preorden\n 4. Imprimir en Inorden \n 5. Imprimir Postorden \n 6. Libreria externa \n 7. Salir\n");
  scanf("%d", &i);
  return i;
}

struct nodo* crearNodo(int dato1){
	struct nodo*ptrN;
	ptrN=(struct nodo*)malloc(sizeof(struct nodo));
	ptrN->dato=dato1;
	ptrN->hijo_izq=NULL;
	ptrN->hijo_der=NULL;
	return ptrN;
}
void meter(int x, struct nodo **ptrRaiz){

	if(*ptrRaiz== NULL)
		*ptrRaiz=crearNodo(x);
	
	else if(((*ptrRaiz)->dato)>x){
		meter(x,&((*ptrRaiz)->hijo_izq));
	}
	else{
		meter(x,&((*ptrRaiz)->hijo_der));
	}
	return;
}

void imprimirArbol(struct nodo*ptrA, int contador){
	int i,j;
	i=contador;
	if(ptrA != NULL){
		imprimirArbol(ptrA->hijo_der,i+1);
		printf("\n");
		for(j=0;j<i;j++)
			printf("-");
		printf("%d",ptrA->dato);
		imprimirArbol(ptrA->hijo_izq,i+1);
	}
}

void imprimirPreorden(struct nodo* ptrRaiz){
	if(ptrRaiz!=NULL){
		printf("Dato:%d \n",ptrRaiz->dato);
		imprimirPreorden(ptrRaiz->hijo_izq);
		imprimirPreorden(ptrRaiz->hijo_der);
	}
	return;
}

void imprimirInorden(struct nodo* ptrRaiz){
	if(ptrRaiz!=NULL){
		imprimirInorden(ptrRaiz->hijo_izq);
		printf("Dato:%d \n",ptrRaiz->dato);
		imprimirInorden(ptrRaiz->hijo_der);
	}
	return;
}

void imprimirPostorden(struct nodo* ptrRaiz){
	if(ptrRaiz!=NULL){
		imprimirPostorden(ptrRaiz->hijo_izq);
		imprimirPostorden(ptrRaiz->hijo_der);
		printf("Dato:%d \n",ptrRaiz->dato);
	}
	return;
}
	
	
int main(){
	int midata;
	struct nodo *miptrRef1,**miptrRef2;
	miptrRef2=&miptrRef1;
	miptrRef1=NULL;
	for(;;){
		switch(menu()){
			case 1:
				printf("Ingresa el dato que desees anexar al arbol\n");
				scanf("%d",&midata);
				meter(midata,miptrRef2);
				break;
			case 2:
				imprimirArbol(miptrRef1,0);
				break;
			case 3:
				imprimirPreorden(miptrRef1);
				break;
			case 4:
				imprimirInorden(miptrRef1);
				break;		
			case 5:
				imprimirPostorden(miptrRef1);
				break;
			
			case 6:
				system("cls");
				printf("Libreria externa por usuario\n");
				switch(menuExtLib()){
					int aux;
					case 1:
						printf("Numero de Nodos: %d\n",numNodos(miptrRef2));
					break;
					case 2:
						printf("Numero de Hojas %d\n",numHojas(miptrRef2));
					break;
					case 3:
						printf("Suma de nodos totales %d\n",sumNodosT(miptrRef2));
					break;
					case 5:
						printf("Nodos internos totales %d\n",numNodosIn(miptrRef2));
					break;
					case 7:
						printf("El minimo numero en el arbol es %d\n",getMinNod(miptrRef2));
					break;
					case 8:
						printf("El maximo numero en el arbol es %d\n",getMaxNod(miptrRef2));
					break;
					case 9:
						scanf("%d",&aux);
						printf("El numero de nodos mayores es de %d\n",numNodosMayores(miptrRef2,aux));
					break;
				}
					
				break;
			
			case 7:
				exit(0);
			break;
		}
	}

	return 0;
}