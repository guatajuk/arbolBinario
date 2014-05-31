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
 |Julián Alberto Gaitán Arias                   |
 |Universidad de Caldas - Facultad de Ingeniería|
 |Ingeniería en Sistemas y Computación          |
 |Twitter: @guatajuk                            |
 *--------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int menu (){
	int opc;
	do{
		printf ("\n------------------------");
		printf ("\nArboles Binarios - Menu");
		printf ("\n------------------------");
		printf ("\n1. Agregar nodos a el arbol");
		printf ("\n2. Eliminar todos los nodos del arbol");
		printf ("\n3. Mostrar recorridos");
		printf ("\n4. Salir");
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
	return 0;
}