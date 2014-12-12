

/**
 *  
 *       
 * \mainpage Solución PEC3 - Punto 2

Para generar la documentación del código de la biblioteca de operaciones sobre matrices
usaréis Doxygen.
Por cada archivo (matrices.h y matrices.c) de la copia local del depósito crearéis un comentario
de cabecera en el que, usando siempre etiquetas de Doxygen, indicaréis, de forma resumida y
también de forma detallada, la información que se encuentra en el archivo, el autor y la fecha
en la que generáis la documentación.
Después, en el archivo matrices.h documentaréis la estructura de datos matriz de forma
general (es decir, toda la estructura), pero también haciendo un comentario por cada uno de
sus campos.
En el archivo matrices.c, documentaréis cada una de las funciones programadas. En este caso
incluiréis, usando siempre etiquetas Doxygen, una descripción breve y una detallada, la
descripción de los parámetros de la función (indicando si son de entrada, de salida o de
entrada/salida), la descripción del valor de retorno de la función y, en el caso de las funciones
que para las operaciones (suma, resta, etc.), enlaces a todas las otras operaciones.
La documentación la generaréis en formato html en un directorio que denominaréis doc (creado
también a la copia local del depósito).
Finalmente, añadiréis este directorio al depósito y actualizaréis los archivos matrices.h y
matrices.c con las versiones documentadas


 * \author Roger Calderón Moreno
 * \date Diciembre de 2014
	 */

#include <stdio.h>
#include "matrix.h"
/**
 *  
 * 	- Este archivo inicia el programa para operar matrices segun los requerimientos planteados.    
 *        asi como la definición de la estructura que almacenara los datos de la matriz.
 *
 */
void main()
{
	t_matrix *A, *B, *C, *D, *E;
	A = Create_M(5);
	B = Create_M(5);
	Print_M(A); Print_E(A,3,3);
	Print_M(B);	
	C = Add_M( A, B );
	D = Subs_M( A, B );
	E = Mult_M( A, B );
	Log_M(A);
    	Print_M( A ); Print_E(A,3,3);
    	Print_M( C ); Print_E(C,3,3);
    	Print_M( D ); Print_E(D,3,3);
    	Print_M( E ); Print_E(E,3,3);
    	Eliminate_M(A);
    	Eliminate_M(B);
    	Eliminate_M(C);
    	Eliminate_M(D);
    	Eliminate_M(E);
}
