#include <stdio.h>
#include <stdlib.h>
#include "io.h"

// --------------------------- inicio biblioteca

/**
  Definicao de tipo arranjo com inteiros
  baseado em estrutura
 */
typedef
struct s_int_Array
{
	int length;
	ints data ;
	int ix ;
}
int_Array;

/**
  Definicao de referencia para arranjo com inteiros
  baseado em estrutura
 */
typedef int_Array* ref_int_Array;

/**
  new_int_Array - Reservar espaco para arranjo com inteiros
  @return referencia para arranjo com inteiros
  @param n - quantidade de datos
 */
ref_int_Array new_int_Array ( int n )
{
// reserva de espaco
	ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array));
// estabelecer valores padroes
	if ( tmpArray == NULL )
	{
		IO_printf ( "\nERRO: Falta espaco.\n" );
	}
	else
	{
		tmpArray->length = 0;
		tmpArray->data = NULL;
		tmpArray->ix = -1;
		if ( n>0 )
		{
			// guardar a quantidade de dados
			tmpArray->length = n;
			// reservar espaco para os dados
			tmpArray->data = (ints) malloc (n * sizeof(int));
			// definir indicador do primeiro elemento
			tmpArray->ix = 0;
		} // end if
	} // end if
// retornar referencia para espaco reservado
	return ( tmpArray );
} // end new_int_Array ( )
/**
  free_int_Array - Dispensar espaco para arranjo com inteiros
  @param tmpArray - referencia para grupo de valores inteiros
 */
void free_int_Array ( ref_int_Array tmpArray )
{
// testar se ha' dados, antes de reciclar o espaco
	if ( tmpArray != NULL )
	{
		if ( tmpArray->data != NULL )
		{
			free ( tmpArray->data );
		} // end if
		free ( tmpArray );
	} // fim se
} // end free_int_Array ( )
/**
  printIntArray - Mostrar arranjo com valores inteiros.
  @param array - grupo de valores inteiros
 */
void printIntArray ( int_Array array )
{
// mostrar valores no arranjo
	if ( array.data )
	{
		for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
		{
			// mostrar valor
			printf ( "%2d: %d\n", array.ix, array.data [ array.ix ] );
		} // end for
	} // end if
} // end printIntArray ( )

/**
  IO_readintArray - Ler arranjo com valores inteiros.
  @return arranjo com valores lidos
 */
int_Array IO_readintArray ( )
{
// definir dados locais
	chars text = IO_new_chars ( STR_SIZE );
	static int_Array array;
// ler a quantidade de dados
	do
	{
		array.length = IO_readint ( "\nlength = " );
	}
	while ( array.length <= 0 );
// reservar espaco para armazenar
	array.data = IO_new_ints ( array.length );
// testar se ha' espaco
	if ( array.data == NULL )
	{
		array.length = 0; // nao ha' espaco
	}
	else
	{
		// ler e guardar valores em arranjo
		for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
		{
			// ler valor
			strcpy ( text, STR_EMPTY );
			array.data [ array.ix ]
			= IO_readint ( IO_concat (
				IO_concat ( text, IO_toString_d ( array.ix ) ), " : " ) );
		} // end for
	} // end if
// retornar arranjo
	return ( array );
} // end IO_readintArray ( )

/**
  fprintIntArray - Gravar arranjo com valores inteiros.
  @param fileName - nome do arquivo
  @param array - grupo de valores inteiros
 */
void fprintIntArray ( chars fileName, int_Array array )
{
// definir dados locais
	FILE* arquivo = fopen ( fileName, "wt" );
// gravar quantidade de dados
	fprintf ( arquivo, "%d\n", array.length );
// gravar valores no arquivo, se existirem
	if ( array.data )
	{
		for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
		{
			// gravar valor
			fprintf ( arquivo, "%d\n", array.data [ array.ix ] );
		} // end for
	} // end if
	
// fechar arquivo
	fclose ( arquivo );
} // end fprintIntArray ( )

/**
  freadArraySize - Ler tamanho do arranjo com valores inteiros.
  @return quantidade de valores lidos
  @param fileName - nome do arquivo
 */
int freadArraySize ( chars fileName )
{
// definir dados locais
	int n = 0;
	FILE* arquivo = fopen ( fileName, "rt" );
// testar a existencia
	if ( arquivo )
	{
		// ler a quantidade de dados
		fscanf ( arquivo, "%d", &n );
		if ( n <= 0 )
		{
			IO_printf ( "\nERRO: Valor invalido.\n" );
			n = 0;
		} // end if
		fclose ( arquivo );
	} // end if
// retornar dados lidos
	return ( n );
} // end freadArraySize ( )

/**
  fscanIntArray - Ler arranjo com valores inteiros.
  @return arranjo com os valores lidos
  @param fileName - nome do arquivo
  @param array - grupo de valores inteiros
 */
int_Array fscanIntArray ( chars fileName )
{
// definir dados locais
	int x = 0;
	int y = 0;
	FILE* arquivo = fopen ( fileName, "rt" );
	static int_Array array;
// testar a existencia
	if ( arquivo )
	{
		// ler a quantidade de dados
		fscanf ( arquivo, "%d", &array.length );
		// testar se ha' dados
		if ( array.length <= 0 )
		{
			IO_printf ( "\nERRO: Valor invalido.\n" );
			array.length = 0; // nao ha' dados
		}
		else
		{
			// reservar espaco
			array.data = IO_new_ints ( array.length );
			// testar a existência
			if ( array.data )
			{
				// ler e guardar valores em arranjo
				array.ix = 0;
				while ( ! feof ( arquivo ) &&
					array.ix < array.length )
				{
					// ler valor
					fscanf ( arquivo, "%d", &(array.data [ array.ix ]) );
					// passar ao proximo
					array.ix = array.ix + 1;
				} // end while
			} // end if
		} // end if
	} // end if
// retornar dados lidos
	return ( array );
} // end fscanIntArray ( )


/**
  copyIntArray - Copiar arranjo com valores inteiros.
  @return referencia para copia do arranjo
  @param fileName - nome do arquivo
  @param array - grupo de valores inteiros
 */
ref_int_Array copyIntArray ( int_Array array )
{
// definir dados locais
	int x = 0;
	int y = 0;
	ref_int_Array copy;
	if ( array.length <= 0 )
	{
		IO_printf ( "\nERRO: Valor invalido.\n" );
		array.length = 0;
	}
	else
	{
		// reservar area
		copy = new_int_Array ( array.length );
		// testar se ha' descritor
		if ( copy )
		{
			copy->length = array.length;
			copy->data = IO_new_ints ( copy->length );
			// testar se ha' espaco e dados
			if ( copy->data == NULL || array.data == NULL )
			{
				printf ( "\nERRO: Falta espaco ou dados." );
			}
			else
			{
				// ler e copiar valores
				for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
				{
					// copiar valor
					copy->data [ array.ix ] = array.data [ array.ix ];
				} // end for
			} // end if
		} // end if
	} // end if
// retornar dados lidos
	return ( copy );
} // end copyIntArray ( )

// --------------------------- fim biblioteca
