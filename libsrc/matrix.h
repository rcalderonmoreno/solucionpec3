/**
 * @file matrix.h
 * @author Roger Calderón Moreno
 * @date Diciembre de 2014
 * @brief Este archivo contiene la información de las definiciones del archivo de cabecera matrix.h
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */

/** 
* 
 * @struct t_matrix
 * - Representa la estructura que contiene los datos de la matriz y el tamaño definido para ella. 
*
 */
typedef struct{
	int dim; ///< Esta variable representa el tamaño de la matriz, entendiendo que se manejan matrices cuadradas, debe ser un valor mayor a cero y de tipo entero positivo.
	float **m; ///< Esta variable de tipo apuntador se utiliza para direccionar las posiciones de memoria asignada a la matriz.
}t_matrix;

t_matrix *Create_M( int dim );

void Eliminate_M( t_matrix *m );

t_matrix *Add_M(t_matrix *A, t_matrix *B);

t_matrix *Subs_M(t_matrix *A, t_matrix *B);

t_matrix *Mult_M(t_matrix *A, t_matrix *B);

void Log_M(t_matrix *A);

int Print_E(t_matrix *m, int i, int j);

int Print_M(t_matrix *m);


