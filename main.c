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

typedef struct binaryTree {
	int data;
	struct binaryTree *rightChild;
	struct binaryTree *leftChild;
}binaryTree;

typedef struct linkedList {
	struct binaryTree leaf;
	struct linkedList *next;
}linkedList;

void push (linkedList **list, binaryTree leaf){
	if (*list == NULL){
		*list = (linkedList *) malloc (sizeof(linkedList));
		(*list) -> leaf = leaf;
		(*list) -> next = NULL;
	}
	else{
		linkedList *aux = NULL; 
		aux = (linkedList *) malloc (sizeof(linkedList));
		aux -> leaf = leaf;
		aux -> next = *list;
		*list = aux;
	}
}

void showStack (linkedList *list){
	if (list != NULL){
		linkedList *aux = list;
		while (aux != NULL){
			binaryTree *leaf;
			leaf = (binaryTree *) malloc (sizeof(binaryTree));	
			*leaf = aux -> leaf;
			printf ("\t%d", leaf -> data);
			free(leaf);
			aux = aux -> next;
		}
	}
}

void addNode (binaryTree **root, int number){
	if (*root == NULL){
		*root = (binaryTree *) malloc (sizeof(binaryTree));
		(*root) -> data = number;
		(*root) -> leftChild = NULL;
		(*root) -> rightChild = NULL;
	}
	else{
		if (number < (*root) -> data){
			addNode(&(*root) -> leftChild, number);
		}
		else{
			addNode(&(*root) -> rightChild, number);
		}
	}
}

void preOrder (binaryTree *root){
	if (root != NULL){
		printf ("\t%d", root -> data);
		preOrder (root -> leftChild);
		preOrder (root -> rightChild);
	}
}

void postOrder (binaryTree *root){
	if (root != NULL){
		postOrder (root -> leftChild);
		postOrder (root -> rightChild);
		printf ("\t%d", root -> data);
	}
}

void inOrder (binaryTree *root){
	if (root != NULL){
		inOrder (root -> leftChild);
		printf ("\t%d", root -> data);
		inOrder (root -> rightChild);
	}
}

int countLeaves (binaryTree *root){
	if (root == NULL){
		return 0;
	}
	if (root -> rightChild == NULL && root -> leftChild == NULL){
		printf ("\n%d Es hoja", root -> data);
		return 1;
	}
	else{
		return countLeaves(root -> leftChild) + countLeaves(root -> rightChild);
	}
}

int treeHeight (binaryTree *root){
	if(root != NULL){
		int leftHeight = 1 + treeHeight(root -> leftChild);
		int rightHeight = 1 + treeHeight (root -> rightChild);
		if (leftHeight > rightHeight){
			return leftHeight;
		}
		else{
			return rightHeight;
		}
	}
	return 0;
}

void showLevel(binaryTree *root, int level) {
	if (root != NULL){
		if (level == 1) {
			printf ("%d \t", root -> data);
		} 
		else {
			showLevel(root -> leftChild, level-1);
			showLevel(root -> rightChild, level-1);
		}	
	}
}

void showInvertedTree(binaryTree *root){
    int height = treeHeight(root);
    for (int level = height; level >= 1; level--){
    	printf ("\nNivel %d -> ", level);
        showLevel(root, level);
	}
}

void showTree(binaryTree *root) {
	int height = treeHeight(root);
	for (int level = 1; level <= height; level++) {
		printf ("\nNivel %d -> ", level);
		showLevel(root, level);	
	}
}

void preload (binaryTree **root){
	addNode (&(*root), 10);
 	addNode (&(*root), 5);
 	addNode (&(*root), 14);
 	addNode (&(*root), 4);
	addNode (&(*root), 7);
	addNode (&(*root), 12);
	addNode (&(*root), 16);
	addNode (&(*root), 2);
	addNode (&(*root), 3);
	addNode (&(*root), 6);
	addNode (&(*root), 8);
	addNode (&(*root), 11);
	addNode (&(*root), 13);
	addNode (&(*root), 15);
	addNode (&(*root), 17);
	printf ("Se han cargado 15 valores predeterminados");
}

int menu (){
	int opc;
	do{
		printf ("\n---------------------------------");
		printf ("\nArboles Binarios - Menu Principal");
		printf ("\n---------------------------------");
		printf ("\n1. Agregar nodos al arbol");
		printf ("\n2. Eliminar todos los nodos del arbol");
		printf ("\n3. Recorridos");
		printf ("\n4. Contar hojas");
		printf ("\n5. Calcular altura");
		printf ("\n7. Carga rapida");
		printf ("\n0. Salir");
		printf ("\n\tDigite su opción: ");
		scanf ("%d", &opc);
		if (opc < 0 || opc > 7){
			printf ("Error - Opcion incorrecta");
			getchar();
			system("clear");
		}
	}while (opc < 0 || opc > 7);
	return opc;
}

int traversalMenu (){
	int opc;
	do{
		printf ("\n-----------------------------");
		printf ("\nArboles Binarios - Recorridos");
		printf ("\n-----------------------------");
		printf ("\n1. Preorden");
		printf ("\n2. Inorden");
		printf ("\n3. Postorden");
		printf ("\n4. Niveles");
		printf ("\n5. Niveles invertidos");
		printf ("\n0. Volver");
		printf ("\n\tDigite su opción: ");
		scanf ("%d", &opc);
		if (opc < 0 || opc > 5){
			printf ("\nError, valor fuera del rango permitido, presione cualquier tecla para continuar\n");
			getchar();
			system("clear");
		}
	}while(opc < 0 || opc > 5);
	return opc;
}

int main (){
	system("clear");
	int opc;
	int aux;
	int num;
	binaryTree *root = NULL;
	linkedList *list = NULL;
	do {
		opc = menu();
		switch(opc){
			case 1:
 				printf ("\nDigite un number: ");
 				scanf("%d", &num);
 				//addNode (&(*root), num);
 				system("clear"); 
 				printf ("Se ha agregado el numero %d", num);
			break;
			case 2:
				system("clear"); 
				root = NULL;
				printf ("Se ha borrado el arbol");
			break;
			case 3:	
				system("clear");
				do{
					switch (aux = traversalMenu()){
						case 1: 
							system("clear");
							printf("\nPreorden: ");
							preOrder(root);
						break;
						case 2: 
							system("clear");
							printf ("\nInorden: ");
							inOrder(root);
						break;
						case 3: 
							system("clear");
							printf ("\nPostorden: ");
							postOrder(root);
						break;
						case 4:
							system("clear");
 							showTree(root);
 						break;
 						case 5:
 							system("clear");
 							showInvertedTree(root);
 						break;	
					}
				}while (aux != 0);
				system("clear");
			break;
			case 4:
				system("clear");
				printf ("\nEl arbol tiene %d hojas", countLeaves(root));
			break;
			case 5:
				system("clear");
				printf ("\nLa treeHeight del arbol es de %d niveles", treeHeight(root));
			break;
 			case 6:
 				
 			break;
 			case 7: 
				system("clear");
				preload(&root);
 			break;
		}
	}while (opc != 0);
	system("clear");
	return 0;
}