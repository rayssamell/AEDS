/*
EXEMPLOS 0700 - 
Aluna: Rayssa Mell de Souza Silva - 860210 
*/

#include<stdio.h>
#include "io.h"

/**
  writeInts - Gravar em arquivo texto certa quantidade de valores.
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void writeInts ( chars fileName, int x )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "wt" );
	int y = 0;
	// repetir para a quantidade de dados
	for ( y = 1; y <= x; y = y + 1 )
	{
		// gravar valor
		fprintf ( arquivo, "%d\n", y );
	} // end for
	// fechar arquivo (INDISPENSAVEL para gravacao)
	fclose ( arquivo );
} // end writeInts ( )

/**
  Method_01 - Mostrar certa quantidade de valores.
 */
void method_01 ( )
{
	// identificar
	IO_id ( "Method_01 - v0.0" );
	// executar o metodo auxiliar
	writeInts ( "DADOS1.TXT", 10 );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  readInts - Ler de arquivo texto certa quantidade de valores.
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void readInts ( chars fileName )
{
// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	int x = 0;
// tentar ler o primeiro
	fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados
	while ( ! feof ( arquivo ) )
	{
		// mostrar valor
		printf ( "%d\n", x );
		// tentar ler o proximo
		fscanf ( arquivo, "%d", &x );
	} // end while
	// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
} // end readInts ( )

/**
  Method_02.
 */
void method_02 ( )
{
// identificar
	IO_id ( "Method_02 - v0.0" );
// executar o metodo auxiliar
	readInts ( "DADOS1.TXT" );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  writeDoubles - Gravar em arquivo texto certa quantidade de valores.
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void writeDoubles ( chars fileName, int x )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "wt" );
	int y = 0;
	// gravar quantidade de valores
	IO_fprintf ( arquivo, "%d\n", x );
	// repetir para a quantidade de dados
	for ( y = 1; y <= x; y = y + 1 )
	{
		// gravar valor
		IO_fprintf ( arquivo, "%lf\n", (0.1*y) );
	} // end for
	// fechar arquivo (INDISPENSAVEL para gravacao)
	fclose ( arquivo );
} // end writeDoubles ( )

/**
  Method_03.
 */
void method_03 ( )
{
// identificar
	IO_id ( "Method_03 - v0.0" );
// executar o metodo auxiliar
	writeDoubles ( "DADOS2.TXT", 10 );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  readDoubles - Ler de arquivo texto certa quantidade de valores.
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void readDoubles ( chars fileName )
{
// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	int x = 0 ;
	int y = 1 ;
	double z = 0.0;
// tentar ler a quantidade de dados
	fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados e
// quantidade nao tiver sido alcancada
	while ( ! feof ( arquivo ) && y <= x )
	{
		// tentar ler
		fscanf ( arquivo, "%lf", &z );
		// mostrar valor
		printf ( "%2d: %lf\n", y, z );
		// passar ao proximo
		y = y + 1;
	} // end while
// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
} // end readDoubles ( )
/**
  Method_04.
 */
void method_04 ( )
{
// identificar
	IO_id ( "Method_04 - v0.0" );
// executar o metodo auxiliar
	readDoubles ( "DADOS2.TXT" );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/*
writeText - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
	@param x - quantidade de valores
*/
	void writeText ( chars fileName )
{
// definir dados
	FILE* arquivo = fopen ( fileName, "wt" );
	chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
	IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
	do
	{
		// ler do teclado
		strcpy ( linha, IO_readln ( "" ) );
		// gravar valor
		IO_fprintf ( arquivo, "%s\n", linha );
	}
	while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
	fclose ( arquivo );
} // end writeText ( )

/**
  Method_05.
 */
void method_05 ( )
{
// identificar
	IO_id ( "Method_05 - v0.0" );
// executar o metodo auxiliar
	writeText ( "DADOS3.TXT" );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  readText - Ler de arquivo texto certa quantidade de valores.
  @param fileName - nome do arquivo
 */
void readText ( chars fileName )
{
// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	chars linha = IO_new_chars ( STR_SIZE );
// tentar ler o primeiro
	strcpy ( linha, IO_freadln ( arquivo ) );
// repetir enquanto houver dados
	while ( ! feof (arquivo) &&
		strcmp ( "PARAR", linha ) != 0 )
	{
		// mostrar valor
		printf ( "%s\n", linha );
		// tentar ler o proximo
		strcpy ( linha, IO_freadln ( arquivo ) );
	} // end while
// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
} // end readText ( )
/**
  Method_06.
 */
void method_06 ( )
{
// identificar
	IO_id ( "Method_06 - v0.0" );
// executar o metodo auxiliar
	readText ( "DADOS3.TXT" );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  copyText - Copiar arquivo texto.
  @param fileOut - nome do arquivo de saida (destino)
  @param fileIn - nome do arquivo de entrada (origem )
 */
void copyText ( chars fileOut, chars fileIn )
{
// definir dados
	FILE* saida = fopen ( fileOut, "wt" );
	FILE* entrada = fopen ( fileIn , "rt" );
	chars linha = IO_new_chars ( STR_SIZE );
	int contador = 0;
// ler da origem
	strcpy ( linha, IO_freadln ( entrada ) );
// repetir enquanto houver dados
	while ( ! feof ( entrada ) )
	{
		// contar linha lida
		contador = contador + 1;
		// gravar no destino,
		// EXCEPCIONALMENTE sem a ultima linha, nesse caso
		if ( strcmp ( "PARAR", linha ) != 0 )
		{
			IO_fprintln ( saida, linha );
		} // end if
		// ler da origem
		strcpy ( linha, IO_freadln ( entrada ) );
	} // end while
// informar total de linhas copiadas
	IO_printf ( "Lines read = %d\n", contador );
// fechar arquivos
	fclose ( saida );
	fclose ( entrada );
} // end copyText ( )
/**
  Method_07.
 */
void method_07 ( )
{
// identificar
	IO_id ( "Method_07 - v0.0" );
// executar o metodo auxiliar
	copyText ( "DADOS4.TXT", "DADOS3.TXT" );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
  appendText - Gravar em arquivo texto certa quantidade de valores.
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void appendText ( chars fileName )
{
// definir dados
	FILE* arquivo = fopen ( fileName, "at" );
	chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
	IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
	do
	{
		// ler do teclado
		strcpy ( linha, IO_readln ( "" ) );
		// gravar valor
		IO_fprintln ( arquivo, linha );
	}
	while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
	fclose ( arquivo );
} // end appendText ( )
/**
  Method_08.
 */
void method_08 ( )
{
// identificar
	IO_id ( "EXEMPLO0710 - Method_08 - v0.0" );
// executar o metodo auxiliar
	appendText ( "DADOS4.TXT" );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
  readWords - Ler palavras de arquivo.
  @param fileName - nome do arquivo
 */
void readWords ( chars fileName )
{
// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	chars linha = IO_new_chars ( STR_SIZE );
// tentar ler a primeira
	strcpy ( linha, IO_fread ( arquivo ) );
// repetir enquanto houver dados
	while ( ! feof (arquivo) &&
		strcmp ( "PARAR", linha ) != 0 )
	{
		// mostrar valor
		printf ( "%s\n", linha );
		// tentar ler o proximo
		strcpy ( linha, IO_fread ( arquivo ) );
	} // end while
// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
} // end readWords ( )
/**
  Method_09.
 */
void method_09 ( )
{
// identificar
	IO_id ( "Method_09 - v0.0" );
// executar o metodo auxiliar
	readWords ( "DADOS4.TXT" );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
  searchWord - Procurar palavra em arquivo.
  @return true, se encontrar; false, caso contrario
  @param fileName - nome do arquivo
  @param word - palavra a procurar
 */
bool searchWord ( chars fileName, chars word )
{
// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	chars linha = IO_new_chars ( STR_SIZE );
// tentar ler a primeira
	strcpy ( linha, IO_fread ( arquivo ) );
// repetir enquanto houver dados
	while ( ! feof (arquivo) &&
		strcmp ( word, linha ) != 0 )
	{
		// tentar ler o proximo
		strcpy ( linha, IO_fread ( arquivo ) );
	} // end while
// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
	
// retornar resultado
	return ( strcmp ( word, linha ) == 0 );
} // end ifarchdWord ( )
/**
  Method_10.
 */
void method_10 ( )
{
// identificar
	IO_id ( "Method_10 - v0.0" );
// procurar palavra
	IO_printf ( "Procurar (\"%s\") = %d\n", "pqr", searchWord ( "DADOS4.TXT", "pqr" ) );
	IO_printf ( "Procurar (\"%s\") = %d\n", "pqs", searchWord ( "DADOS4.TXT", "pqs" ) );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

int main(){
		int opcao = 0;
		printf ( "%s\n", "Exemplos 0700 - Programa = v0.0" );
		printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
		printf ( "\n" ); // mudar de linha
		
		do{
			printf("\n%s\n", "\nOpcoes: ");
			printf("\n%s", "0 - Terminar");
			printf("\n%s", "1 - Metodo_01	2 - Metodo_02");
			printf("\n%s", "3 - Metodo_03	4 - Method_04");
			printf("\n%s", "5 - Metodo_05	6 - Method_06");
			printf("\n%s", "7 - Metodo_07	8 - Method_08");
			printf("\n%s", "9 - Metodo_09	10 - Method_10");
			
			printf("\n%s", "\nOpcao = ");
			scanf("%d", &opcao);
			getchar();
			// para mostrar a opcao lida
			printf ( "\n%s%d", "Opcao =  ", opcao );
			getchar();
			//testar valor
			switch (opcao) {
			case 1:
				method_01();
				break;
			case 2:
				method_02();
				break;
			case 3:
				method_03();
				break;
			case 4:
				method_04();
				break;
			case 5:
				method_05();
				break;
			case 6:
				method_06();
				break;
			case 7:
				method_07();
				break;
			case 8:
				method_08();
				break;
			case 9:
				method_09();
				break;
			case 10:
				method_10();
				break;
			default:
				printf("Erro: opcao invalida.");
				break;
			}
			
		}while(opcao != 0);
		
		printf("Aperte ENTER para terminar.");
		getchar();
		return(0);
		
}

