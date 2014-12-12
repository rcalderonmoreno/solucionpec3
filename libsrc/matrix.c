/**
 * @file matrix.c
 * @author Roger Calderón Moreno
 * @date Diciembre de 2014
 * @brief Este archivo contiene la información detallada de las funciones definidas para  el archivo de cabecera matrix.c
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "matrix.h"



/**
  @brief Esta función tiene como objetivo crear un matriz cuadrada de tamaño dim, con asignación dinamica de memoria.
  @param int dim, es el tamaño que tendra la matriz de dimxdim.  
  @returns Devuelve el puntero de la matriz creada. 
 */
t_matrix *Create_Empty( int dim )
{
	t_matrix *aux;
	int i, j;

	if (!(aux=malloc( sizeof(t_matrix))))
		return NULL;
	aux->dim = dim;
	if (!(aux->m = malloc(dim*sizeof(float *)))){
		free( aux );
		return NULL;
	}
	for( i=0; i < dim; i++ )
		if (!(aux->m[i] = malloc(dim*sizeof( float )))){
			for( j=1; j < i; j++)
				free(aux->m[j]);
			free(aux);
			return NULL;
		}
	return aux;
}

/**
  @brief Esta función creará e inicializará, con números aleatorios reales entre 0 y 1000 , una matriz de dimensión dim x dim. 
  @param int dim, es el tamaño que tendra la matriz de dimxdim.  
  @returns devuelve la dirección de la matriz creada o NULL si no se puede crear la matriz. 
 */

t_matrix *Create_M(int dim)
{
	t_matrix *aux;
	int i, j;

	sleep( 1 );
	srandom( time( NULL ) );
   	if ( !(aux = Create_Empty( dim ))) return NULL;

	for (i = 0; i < dim-1; i++)
		for (j = 0; j < dim-1; j++)
			aux->m[i][j] = 1.0*(random()%1000);

	return aux;
}
/**
  @brief Esta función eliminará la matriz recibida como parámetro, liberando la memoria reservada en su creación, no retorna ningun valor.
  @param Recibe como parametro un apuntador con la dirección de memoria de la matriz a eliminar.  
 */
void Eliminate_M(t_matrix *m)
{
	int i;

	for( i=0; i < m->dim; i++ )
		free(m->m[i]);
	free( m );
}



/**
  @brief Esta función devuelve una nueva matriz que será el resultado de la suma de los elementos de las matrices pasadas como parámetros (A + B), o NULL si no se puede hacer la operación.
  @param apuntador de la matriz A.
  @param apuntador de la matriz B.    
  @returns Devuelve el puntero de la nueva matriz. 
 */
t_matrix *Add_M(t_matrix *A, t_matrix *B)
{
	int i,j;
	t_matrix *aux;

	if ( A->dim != B->dim) return NULL;
	if (!(aux=Create_Empty(A->dim))) return NULL;

	for(i=0; i<A->dim; i++)
		for(j=0; j<A->dim; j++)
			aux->m[i][j] = A->m[i][j] + B->m[i][j];

	return aux;
}
/**
  @brief Esta función devuelve una nueva matriz que será el resultado de la resta de los elementos de las matrices pasadas como parámetros (A - B), o NULL si no se puede hacer la operación.
  @param apuntador de la matriz A.
  @param apuntador de la matriz B.    
  @returns Devuelve el puntero de la nueva matriz. 
 */
t_matrix *Subs_M(t_matrix *A, t_matrix *B)
{
	int i,j;
	t_matrix *aux;

	if ( A->dim != B->dim) return NULL;
	if (!(aux=Create_Empty(A->dim))) return NULL;

	for(i=0; i<A->dim; i++)
		for(j=0; j<A->dim; j++)
			aux->m[i][j] = A->m[i][j] - B->m[i][j];

	return aux;
}
/**
  @brief Esta función devuelve una nueva matriz que será el resultado de multiplicar las matrices pasadas como parámetros (A * B), o NULL si no se puede hacer la operación.
  @param apuntador de la matriz A.
  @param apuntador de la matriz B.    
  @returns Devuelve el puntero de la nueva matriz. 
 */
t_matrix *Mult_M(t_matrix *A, t_matrix *B)
{
	int i,j,k;
	t_matrix *aux;

	if ( A->dim != B->dim) return NULL;
	if (!(aux=Create_Empty(A->dim))) return NULL;

	for(i=1; i<A->dim; i++)
		for(j=1; j<A->dim; j++){
			aux->m[i][j]=0;
			for( k=1; k<A->dim; k++)
				aux->m[i][j]+=((A->m[i][k])*(B->m[k][j]));
		}
	return aux;
}

/**
  @brief Esta función aplica la operación logaritmo base 10 a todos los elementos de la matriz pasada como parámetro..
  @param apuntador de la matriz A. 
 */
void Log_M(t_matrix *A)
{
	int i,j;

	for(i=0; i<A->dim; i++)
		for(j=0; j < A->dim; j++)
			A->m[i][j]=log10(A->m[i][j]);
}

/**
  @brief Esta función muestra por pantalla el valor del elemento i,j de la matriz pasada como parámetro. Si no existe el elemento no imprime nada.
  @param apuntador de la matriz de la cual debemos obtener los datos.  
  @param int i, posición de la matriz en i.  
  @param int j, posición de la matriz en j.  
  @returns Devuelve 1 si puede imprimir el elemento o 0 sino.
 */
int Print_E(t_matrix *m, int i, int j)
{
	if (m){
		printf("M(%d,%d) = %f\n", i, j, m->m[i][j]);
		return 1;
	}
	return 0;
}

 


/**
  @brief Esta función muestra por pantalla todos los elementos de la matriz por filas.
  @param apuntador de la matriz de la cual debemos obtener los datos.  
  @returns Si no existe la matriz no imprime nada. Devuelve 1 si puede imprimir la matriz y 0 sino.. 
 */
int Print_M(t_matrix *m)
{
	int i, j;

	if (!m) return 0;

	for( i= 0; i < m->dim; i++){
		for( j= 0; j < m->dim; j++)
			printf("%10.2f \t", m->m[i][j]);
		printf("\n");
	}
	printf("\n");
	return 1;
}
