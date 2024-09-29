#include <stdio.h>
#include <stdlib.h>
#include "io.h"

// --------------------------- inicio biblioteca

/**
Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura
*/
typedef
struct s_int_Matrix
{
	int rows ;
	int columns;
	ints* data ;
	int ix, iy ;
}
int_Matrix;

/**
  Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
 */
typedef int_Matrix* ref_int_Matrix;

/**
  new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
  @return referencia para arranjo com inteiros
  @param rows - quantidade de dados
  @param columns - quantidade de dados
 */
ref_int_Matrix new_int_Matrix ( int rows, int columns )
{
// reserva de espaco
	ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));
// estabelecer valores padroes
	if ( tmpMatrix != NULL )
	{
		tmpMatrix->rows = 0;
		tmpMatrix->columns = 0;
		tmpMatrix->data = NULL;
		// reservar espaco
		if ( rows>0 && columns>0 )
		{
			tmpMatrix->rows = rows;
			tmpMatrix->columns = columns;
			tmpMatrix->data = malloc (rows * sizeof(ints));
			if ( tmpMatrix->data )
			{
				for ( tmpMatrix->ix=0;
					tmpMatrix->ix<tmpMatrix->rows;
					tmpMatrix->ix=tmpMatrix->ix+1 )
				{
					tmpMatrix->data [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int));
				} // end for
			} // end if
		} // end if
		tmpMatrix->ix = 0;
		tmpMatrix->iy = 0;
	} // end if
	return ( tmpMatrix );
} // end new_int_Matrix ( )

/**
  free_int_Matrix - Dispensar espaco para arranjo com inteiros
  @param tmpMatrix - referencia para grupo de valores inteiros
 */
void free_int_Matrix ( ref_int_Matrix matrix )
{
// testar se ha' dados
	if ( matrix != NULL )
	{
		if ( matrix->data != NULL )
		{
			for ( matrix->ix=0;
				matrix->ix<matrix->rows;
				matrix->ix=matrix->ix+1 )
			{
				free ( matrix->data [ matrix->ix ] );
			} // end for
			free ( matrix->data );
		} // end if
		free ( matrix );
	} // end if
} // end free_int_Matrix ( )

/**
  printIntMatrix - Mostrar matrix com valores inteiros.
  @param array - grupo de valores inteiros
 */
void printIntMatrix ( ref_int_Matrix matrix )
{
// testar a existencia
	if ( matrix != NULL && matrix->data != NULL )
	{
		// mostrar valores na matriz
		for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
		{
			for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
			{
				// mostrar valor
				printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->iy ] );
			} // end for
			printf ( "\n" );
		} // end for
	} // end if
} // end printIntMatrix ( )

/**
  IO_readintMatrix - Ler arranjo bidimensional com valores inteiros.
  @return referencia para o grupo de valores inteiros
 */
ref_int_Matrix IO_readintMatrix ( )
{
// definir dados locais
	int rows = 0;
	int columns = 0;
	chars text = IO_new_chars ( STR_SIZE );
	// ler a quantidade de dados
	do
	{ rows = IO_readint ( "\nrows = " ); }
	while ( rows <= 0 );
	do
	{ columns = IO_readint ( "\ncolumns = " ); }
	while ( columns <= 0 );
	// reservar espaco para armazenar valores
	ref_int_Matrix matrix = new_int_Matrix ( rows, columns );
	// testar se ha' espaco
	if ( matrix != NULL )
	{
		if ( matrix->data == NULL )
		{
			// nao ha' espaco
			matrix->rows = 0;
			matrix->columns = 0;
			matrix->ix = 0;
			matrix->iy = 0;
		}
		else
		{
			// ler e guardar valores na matriz
			for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
			{
				for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
				{
					// ler e guardar valor
					strcpy ( text, STR_EMPTY );
					matrix->data [ matrix->ix ][ matrix->iy ]
					= IO_readint ( IO_concat (
						IO_concat ( IO_concat ( text, IO_toString_d ( matrix->ix ) ), ", " ),
						IO_concat ( IO_concat ( text, IO_toString_d ( matrix->iy ) ), " : " ) ) );
				} // end for
				printf ( "\n" );
			} // end for
		} // end if
	} // end if
	// retornar dados lidos
	return ( matrix );
} // end IO_readintMatrix ( )

/**
  fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
  @param fileName - nome do arquivo
  @param matrix - grupo de valores inteiros
 */
void fprintIntMatrix ( chars fileName, ref_int_Matrix matrix )
{
// definir dados locais
	FILE* arquivo = fopen ( fileName, "wt" );
// testar se ha' dados
	if ( matrix == NULL )
	{
		printf ( "\nERRO: Nao ha' dados." );
	}
	else
	{
		// gravar quantidade de dados
		fprintf ( arquivo, "%d\n", matrix->rows );
		fprintf ( arquivo, "%d\n", matrix->columns );
		
		if ( matrix->data != NULL )
		{
			// gravar valores no arquivo
			for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
			{
				for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
				{
					// gravar valor
					fprintf ( arquivo, "%d\n", matrix->data [ matrix->ix ][ matrix->iy ] );
				} // end for
			} // end for
		} // end if
		// fechar arquivo
		fclose ( arquivo );
	} // end if
} // end fprintIntMatrix ( )

/**
  freadintMatrix - Ler arranjo bidimensional com valores inteiros.
  @return referencia para o grupo de valores inteiros
  @param fileName - nome do arquivo
 */
ref_int_Matrix freadintMatrix ( chars fileName )
{
// definir dados locais
	ref_int_Matrix matrix = NULL;
	int rows = 0;
	int columns = 0;
	FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
	fscanf ( arquivo, "%d", &rows );
	fscanf ( arquivo, "%d", &columns );
	if ( rows <= 0 || columns <= 0 )
	{
		IO_printf ( "\nERRO: Valor invalido.\n" );
	}
	else
	{
		// reservar espaco para armazenar
		matrix = new_int_Matrix ( rows, columns );
		// testar se ha' espaco
		if ( matrix != NULL && matrix->data == NULL )
		{
			// nao ha' espaco
			matrix->rows = 0;
			matrix->columns = 0;
			matrix->ix = 0;
			matrix->iy = 0;
		}
		else
		{
			// testar a existência
			if ( matrix != NULL )
			{
				// ler e guardar valores na matriz
				matrix->ix = 0;
				while ( ! feof ( arquivo ) && matrix->ix < matrix->rows )
				{
					matrix->iy = 0;
					while ( ! feof ( arquivo ) && matrix->iy < matrix->columns )
					{
						// guardar valor
						fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) );
						// passar ao proximo
						matrix->iy = matrix->iy+1;
					} // end while
					// passar ao proximo
					matrix->ix = matrix->ix+1;
				} // end while
				matrix->ix = 0;
				matrix->iy = 0;
			} // end if
		} // end if
	} // end if
// retornar matriz lida
	return ( matrix );
} // end freadintMatrix ( )

/**
  copyIntMatrix - Copiar matriz com valores inteiros.
  @return referencia para o grupo de valores inteiros
 */
ref_int_Matrix copyIntMatrix ( ref_int_Matrix matrix )
{
// definir dados locais
	ref_int_Matrix copy = NULL;
	if ( matrix == NULL || matrix->data == NULL )
	{
		IO_printf ( "\nERRO: Faltam dados.\n" );
	}
	else
	{
		if ( matrix->rows <= 0 || matrix->columns <= 0 )
		{
			IO_printf ( "\nERRO: Valor invalido.\n" );
		}
		else
		{
			// reservar espaco
			copy = new_int_Matrix ( matrix->rows, matrix->columns );
			// testar se ha' espaco e dados
			if ( copy == NULL || copy->data == NULL )
			{
				printf ( "\nERRO: Falta espaco." );
			}
			else
			{
				// copiar valores
				for ( copy->ix = 0; copy->ix < copy->rows; copy->ix = copy->ix + 1 )
				{
					for ( copy->iy = 0; copy->iy < copy->columns; copy->iy = copy->iy + 1 )
					{
						// copiar valor
						copy->data [ copy->ix ][ copy->iy ]
						= matrix->data [ copy->ix ][ copy->iy ];
					} // end for
				} // end for
			} // end if
		} // end if
	} // end if
	
// retornar copia
	return ( copy );
} // end copyIntMatrix ( )

// --------------------------- fim biblioteca

