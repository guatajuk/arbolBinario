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
		printf ("El valor agregado: %d", (*raiz) -> dato);
	}
	else{
		if ((*raiz) -> dato >= numero){
			agregarNodo(&(*raiz) -> hijoDerecho, numero);
		}
		else{
			agregarNodo(&(*raiz) -> hijoIzquierdo, numero);	
		}
	}
}

void preorden (tipoNodo *raiz){
	if (raiz != NULL){
		printf ("\t%d", raiz -> dato);
		preorden (raiz -> hijoDerecho);
		preorden (raiz -> hijoIzquierdo);
	}
}

int menu (){
	system("clear");
	int opc;
	do{
		printf ("\n------------------------");
		printf ("\nArboles Binarios - Menu");
		printf ("\n------------------------");
		printf ("\n1. Agregar nodos a el arbol");
		printf ("\n2. Eliminar tsodos los nodos del arbol");
		printf ("\n3. Mostrar recorridos");
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

int main (){
	int opc;
	tipoNodo *raiz = NULL;
	int num = 0;
	do {
		opc = menu();
		switch(opc){
			case 1: 
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
			case 3:
				preorden(raiz);
			break;
		}
	}while (opc != 0);
	return 0;
}







