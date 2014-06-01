// The MIT License (MIT)

// Copyright (c) YEAR NAME

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

/*----------------------------------------------*
 |Julián Alberto Gaitán Arias					|
 |Universidad de Caldas - Facultad de Ingeniería|
 |Ingeniería en Sistemas y Computación			|
 |Twitter: @guatajuk							|
 |GitHub: guatajuk								|
 *--------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNodo {
	int dato;
	struct tipoNodo *hijoDerecho;
	struct tipoNodo *hijoIzquierdo;
}tipoNodo;

//tipoNodo *raiz = NULL;

void agregarNodo (tipoNodo **raiz, int numero){
	if (*raiz == NULL){
		*raiz = (tipoNodo *) malloc (sizeof(tipoNodo));
		(*raiz) -> dato = numero;
		(*raiz) -> hijoIzquierdo = NULL;
		(*raiz) -> hijoDerecho = NULL;
		system("clear");
	}
	else{
		if ((*raiz) -> dato >= numero){
			agregarNodo(&(*raiz) -> hijoIzquierdo, numero);	
		}
		else{
			agregarNodo(&(*raiz) -> hijoDerecho, numero);
		}
	}
}

void preOrden (tipoNodo *raiz){
	if (raiz != NULL){
		printf ("\t%d", raiz -> dato);
		preOrden (raiz -> hijoIzquierdo);
		preOrden (raiz -> hijoDerecho);
	}
}

void postOrden (tipoNodo *raiz){
	if (raiz != NULL){
		postOrden (raiz -> hijoIzquierdo);
		postOrden (raiz -> hijoDerecho);
		printf ("\t%d", raiz -> dato);
	}
}

void inOrden (tipoNodo *raiz){
	if (raiz != NULL){
		inOrden (raiz -> hijoIzquierdo);
		printf ("\t%d", raiz -> dato);
		inOrden (raiz -> hijoDerecho);
	}
}

int menu (){
	system("clear");
	int opc;
	do{
		printf ("\n---------------------------------");
		printf ("\nArboles Binarios - Menu Principal");
		printf ("\n---------------------------------");
		printf ("\n1. Agregar nodos a el arbol");
		printf ("\n2. Eliminar tsodos los nodos del arbol");
		printf ("\n3. Recorridos");
		printf ("\n0. Salir");
		printf ("\n\tDigite su opción: ");
		scanf ("%d", &opc);
		if (opc < 0 || opc > 4){
			printf ("\nError, valor fuera del rango permitido, presione cualquier tecla para continuar\n");
			getchar();
			system("clear");
		}
	}while (opc < 0 || opc > 4);
	return opc;
}

int menuRecorridos (){
	int opc;
	do{
		system("clear");
		printf ("\n-----------------------------");
		printf ("\nArboles Binarios - Recorridos");
		printf ("\n-----------------------------");
		printf ("\n1. Preorden");
		printf ("\n2. Inorden");
		printf ("\n3. Postorden");
		printf ("\n4. Carga rapida");
		printf("\n0. Volver");
		printf ("\n\tDigite su opción: ");
		scanf ("%d", &opc);
		if (opc < 0 || opc > 3){
			printf ("\nError, valor fuera del rango permitido, presione cualquier tecla para continuar\n");
			getchar();
			system("clear");
		}
	}while(opc < 0 || opc > 3);
	return opc;
}

int main (){
	int opc;
	int aux;
	int num;
	tipoNodo *raiz = NULL;
	do {
		opc = menu();
		switch(opc){
			case 1: 
 				printf ("\nDigite un numero: ");
 				scanf("%d", &num);
 				agregarNodo (&raiz, num);
			break;
			case 2:
				raiz = NULL;
			case 3:	
				do{
					switch (aux = menuRecorridos()){
						case 1: 
							printf("\nPreorden: ");
							preOrden(raiz);
						break;
						case 2: 
							printf ("\nInorden: ");
							inOrden(raiz);
						break;
						case 3: 
							printf ("\nPostorden: ");
							postOrden(raiz);
						break;
					}
				}while (aux != 0);
			break;
			case 4: 
				agregarNodo (&raiz, 10);
 				agregarNodo (&raiz, 5);
 				agregarNodo (&raiz, 14);
 				agregarNodo (&raiz, 4);
 				agregarNodo (&raiz, 7);
 				agregarNodo (&raiz, 12);
 				agregarNodo (&raiz, 16);
 				agregarNodo (&raiz, 2);
 				agregarNodo (&raiz, 3);
 				agregarNodo (&raiz, 6);
				agregarNodo (&raiz, 8);
 				agregarNodo (&raiz, 11);
 				agregarNodo (&raiz, 13);
				agregarNodo (&raiz, 15);
 				agregarNodo (&raiz, 17);
 			break;
		}
	}while (opc != 0);
	system("clear");
	return 0;
}