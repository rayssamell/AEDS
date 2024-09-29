/* 
Recuperação 2 - 11 /06 /2024 
Aluna: Rayssa Mell de Souza Silva 
Matricula: 860210               
*/

// definir dependencias
#include <stdio.h>
#include "array.h"
#include "matrix.h"
#include "io.h"

/*
-- Aluna: Rayssa Mell de Souza Silva 
-- Matricula: 860210 
-- Method_01 - determinar se os valores no arranjo estão em ordem decrescente
*/

//funcao para determinar se o arranjo esta na ordem decrescente
bool isDecrescent(int_Array a){
	if (a.length <= 1)
		return true;
	
	bool result = true;
	int x = 1;
	
	while (x < a.length && result) { 
		if (a.data[x] >= a.data[x - 1]) {
			result = false;
		}
		x = x + 1;
	}
	
	return result;
}//end isDecrescent()

//funcao para ordenar o arranjo e guardar em arquivo
int_Array ordenar(int_Array a) {
	for (int x = 0; x < a.length; x = x + 1) {
		for (int y = x + 1; y < a.length; y = y + 1) {
			if (a.data[x] < a.data[y]) {
				int temp = a.data[x];
				a.data[x] = a.data[y];
				a.data[y] = temp;
			}
		}
	}
	for (int x = 0; x < a.length; x = x + 1) {
		fprintIntArray("DECRESCENTE.TXT", a);
	}
	return a; 
}//end ordenar()

void method_01(void){
	//identificar
	IO_id("Method_01 - Determinar ordem decrescente.\n");
	//definir dados 
	int_Array  a;
	//ler tamanho de arquivo
	a.length = freadArraySize("DADOS1.TXT");
	//ler dados de arquivo
	a = fscanIntArray("DADOS1.TXT");
	//verificar se esta na ordem decrescente
	bool result = isDecrescent(a);
	if(result){
		printf("\nO arranjo esta ordenado.\n");
	}
	else{
		ordenar(a);
	}
	free(a.data);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_01()

/*
-- Aluna: Rayssa Mell de Souza Silva 
-- Matricula: 860210 
-- Method_02 - inverter a ordem dos elementos do arranjo
*/
//funcao para inverter a ordem dos elementos do arranjo
int_Array inverter (int_Array arranjo2, int_Array arranjo1){
	//comparar tamanho de arranjos
	if(arranjo1.length != arranjo2.length){
		printf("\nERRO: tamanhos incompativeis.\n");
	}else{
		for(int i = 0; i < arranjo1.length; i = i + 1){
			arranjo2.data[i] = arranjo1.data[arranjo1.length - 1 - i];
			//guardar em arquivo o arranjo invertido
			fprintIntArray("INVERTIDOS.TXT", arranjo2);
		}
	}
	return(arranjo2);
}//end inverter()

void method_02(void){
	//identificar
	IO_id("Method_02 - Inverter arranjo.\n");
	
	//definir dados
	int_Array arranjo1;
	int_Array arranjo2;
	
	//chamar funcoes para atribuir dados
	arranjo1.length = freadArraySize("DECRESCENTE.TXT");
	arranjo2.length = arranjo1.length;
	
	//alocar espaco na memoria
	arranjo1.data = (int*)malloc(arranjo1.length * sizeof(int));
	arranjo2.data = (int*)malloc(arranjo2.length * sizeof(int));
	//ler arranjo de arquivo
	arranjo1 = fscanIntArray("DECRESCENTE.TXT");
	//chamar funcao para inverter o arranjo
	inverter(arranjo2, arranjo1);
	//liberar memoria
	free(arranjo1.data);
	free(arranjo2.data);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_02()

/*
-- Aluna: Rayssa Mell de Souza Silva 
-- Matricula: 860210 
-- Method_03 - achar a mediana e a moda
*/

//funcao para calcular mediana
double calcularMediana(int_Array arranjo){
	
	double mediana = 0.0;
	int moda = 0;
	int x = 0;
	
	if(arranjo.length != 0){
		x = arranjo.length / 2;
		if(arranjo.length % 2 == 0){
			mediana = (arranjo.data[x] + arranjo.data[x-1])/2.0;
		}
		else{
			mediana = arranjo.data[x];
		}
	}	
	return (mediana);
}//end calcularMediana()

//funcao para contar quantas vezes o valor aparece
int contarValor(int_Array arranjo, int valor) {
	int contar = 0;
	
	for (int i = 0; i < arranjo.length; i = i + 1) {
		if (arranjo.data[i] == valor) {
			contar = contar + 1;
		}
	}
	return contar;
}//end contarValor()

//funcao para calcular a moda
int moda(int_Array arranjo){
	if(arranjo.data != 0){
		int moda = arranjo.data[0];
		int maxContar = contarValor(arranjo, moda);
		
		for (int i = 1; i < arranjo.length; i++) {
			int valor = arranjo.data[i];
			int contar = contarValor(arranjo, valor);
			if (contar > maxContar) {
				maxContar = contar;
				moda = valor;
			}
		}
		
		return moda;
	}else{
		printf("\nO array esta vazio\n");
	}
}//end moda()


void method_03(void){
	//identificar
	IO_id("Method_03 - Calcular Mediana e Moda.\n");
	//definir dados 
	int_Array arranjo;
	//ler tamanho
	arranjo.length = freadArraySize("DADOS1.TXT");
	//ler dados
	arranjo = fscanIntArray("DADOS1.TXT");
	//chamar funcao para calcular a mediana
	printf("Mediana = %.2lf\n", calcularMediana(arranjo));
	//chamar funcao para calcular a moda
	printf("Moda = %d", moda(arranjo));
	//liberar espaco
	free(arranjo.data);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_03()

/*
-- Aluna: Rayssa Mell de Souza Silva 
-- Matricula: 860210 
-- Method_04 - elementos comuns em arranjos
*/

//funcao para filtrar os elementos comuns nos dois arranjos
void arranjoFiltrar(int_Array a1, int_Array a2){
	int_Array a3;
	//alocar espaco na memoria
	a3.data = (int*)malloc(a1.length * sizeof(int));
	int cont = 0;
	
	for (int i = 0; i < a1.length; i++) {
		for (int j = 0; j < a2.length; j++) {
			if (a1.data[i] == a2.data[j]) {
				// Verificar se o valor já está em a3
				int encontrado = 0;
				for (int k = 0; k < cont; k++) {
					if (a3.data[k] == a1.data[i]) {
						encontrado = 1;
					}
				}
				if (!encontrado) {
					a3.data[cont] = a1.data[i];
					cont++;
				}
			}
		}
	}
	a3.length = cont;
	//guardar em arquivo
	fprintIntArray("FILTRADOS.TXT", a3);
	free(a3.data);
}//end arranjoFiltrar()

void method_04(void){
	//identificar
	IO_id("Method_04 - Elementos comuns em arranjos.\n");
	int_Array a1;
	int_Array a2;
	//ler tamanho
	a1.length = freadArraySize("DADOS1.TXT");
	a2.length = freadArraySize("DADOS2.TXT");
	// Reservar espaço
	a1.data = (int*)malloc(a1.length * sizeof(int));
	a2.data = (int*)malloc(a2.length * sizeof(int));
	//ler dados de arquivo
	a1 = fscanIntArray("DADOS1.TXT");
	a2 = fscanIntArray("DADOS2.TXT");
	//chamar funcao para filtrar e gravar em arquivo
	arranjoFiltrar(a1, a2);
	//liberar espaco
	free(a1.data);
	free(a2.data);
	
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_04()

/*
-- Aluna: Rayssa Mell de Souza Silva 
-- Matricula: 860210 
-- Method_05 - ler arquivo binario, converter para decimal e guardar em arranjo 
*/

//funcao para verificar se o numero e' binario
bool validarBinario(chars linha){
	for (int i = 0; i < strlen(linha); i++) {
		if (linha[i] != '0' && linha[i] != '1') {
			return false;  
		}
	}
	return true;  
}//validarBinario()

//funcao para converter de binario para decimal
int binarioDecimal(chars linha){
	int valor = 0;
	int potencia = strlen(linha) - 1; 
	
	for (int i = 0; i < strlen(linha); i++) {
		if (linha[i] == '1') {
			valor += 1 * pow(2, potencia - i);
		}
	}
	return (valor);
}//end binarioDecimal()

/**
  fscanStringArray - Ler cadeia de caracteres, verificar se e' binario e se for
  converter para decimal e guardar em arranjo.
 */
int_Array fscanStringArray ( chars fileName )
{
// definir dados locais
	FILE* arquivo = fopen ( fileName, "rt" );
	static int_Array array;
	chars linha = IO_new_chars(STR_SIZE);
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
				for (int i = 0; i < array.length; i++) {
					//ler linha em arquivo
					strcpy ( linha, IO_freadln ( arquivo ) );
					//verificar se e' binario
					if (validarBinario(linha)) {
						//converter para decimal e guardar em arranjo
						array.data[i] = binarioDecimal(linha);
					}else{
						//se nao for binario guarda 0
						array.data[i] = 0;
					}
				}
			} // end if
		} // end if
	} // end if
	//fechar arquivo
	fclose(arquivo);
	
	return (array);
} // end fscanIntArray ( )

void method_05(void){
	//identificar
	IO_id("Method_05 - Cadeia de Caracteres.\n");
	//atribuir valor ao array a partir de funcoes
	int_Array array = fscanStringArray("BINARIOS1.TXT");
	//mostrar arranjo apos conversao
	printIntArray(array);
	// liberar espaco
	free(array.data);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_05()

/*
-- Aluna: Rayssa Mell de Souza Silva 
-- Matricula: 860210 
-- Method_06 - ler matriz e montar uma tridiagonal crescente
*/

//funcao para montar matriz tridiagonal crescente
ref_int_Matrix tridiagonalMatrix(int n, ref_int_Matrix matrix2){
	matrix2 = new_int_Matrix(n, n);
	
	if(matrix2->rows > 0 && matrix2->columns > 0){
		int valor = 1;	
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == i || j == i + 1 || j == i - 1) {
					matrix2->data[i][j] = valor++;
				} else {
					matrix2->data[i][j] = 0;
				}
			}
		}
	}else{
		printf("Tamanho Invalido.\n");
	}

	return matrix2;
}//end tridiagonalMatrix()

void method_06(void){
	//identificar
	IO_id("Method_06 - Matriz Tridiagonal Crescente.\n");
	//ler dados de arquivo
	ref_int_Matrix matrix = freadintMatrix("MATRIZ1.TXT");
	//definir dado
	int n = 0;
	//ler dimensoes da matriz
	printf("Digite um valor para definir a matriz: ");
	scanf("%d", &n); getchar();
	//chamar funcao para montar matriz tridiagonal crescente
	ref_int_Matrix matrix2 = new_int_Matrix(n,n);
	matrix2 = tridiagonalMatrix(n, matrix2);
	printf("\nMatriz1.txt: \n");
	printIntMatrix(matrix);
	printf("\nMatriz Tridiagonal Crescente: \n");
	printIntMatrix(matrix2);
	//gravar em arquivo
	fprintIntMatrix("MATRIZ2.TXT", matrix2);
	//liberar espaco
	free_int_Matrix(matrix);
	free_int_Matrix(matrix2);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_06()

/* -- Aluna: Rayssa Mell de Souza Silva 
   -- Matricula: 860210 
   Method_07 - Matriz Tridiagonal Decrescente 
*/

//funcao para montar matriz tridiagonal decrescente
ref_int_Matrix tridiagonalDecrescente(int n, ref_int_Matrix matrix2) {
	
	if(matrix2->rows > 0 && matrix2->columns > 0){
		
		int valor = 1;
		for (int i = n - 1; i >= 0; i = i - 1) {
			for (int j = 0; j < n; j++) {
				if (j == i || j == i - 1 || i == j - 1) {
					matrix2->data[i][j] = valor++;
				} else {
					matrix2->data[i][j] = 0;
				}
			}
		}
	}
	else{
		printf("Tamanho Incompativel.\n");
	}
	
	return matrix2;
}//end tridiagonalDecrescente()

void method_07(void){
	//identificar
	IO_id("Method_07 - Matriz Tridiagonal Decrescente.\n");
	//ler dados de arquivo
	ref_int_Matrix matrix = freadintMatrix("MATRIZ1.TXT");
	//definir dados
	int n = 0;
	//ler dimensoes da matriz
	printf("Digite um valor para definir a matriz: ");
	scanf("%d", &n); getchar();
	//chamar funcao para montar matriz tridiagonal decrescente
	ref_int_Matrix matrix2 = new_int_Matrix(n,n);
	matrix2 = tridiagonalDecrescente(n, matrix2);
	printf("\nMatriz1.txt: \n");
	printIntMatrix(matrix);
	printf("\nMatriz Tridiagonal Crescente: \n");
	printIntMatrix(matrix2);
	//gravar em arquivo
	fprintIntMatrix("MATRIZ4.TXT", matrix2);
	//liberar espaco
	free_int_Matrix(matrix);
	free_int_Matrix(matrix2);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_07()

/* -- Aluna: Rayssa Mell de Souza Silva 
   -- Matricula: 860210 
   Method_08 - Verificar potencias por linha
*/

//funcao para verificar potencia por linha
bool verifica_potencias(ref_int_Matrix matrix) {
	if (matrix->columns < 2) {
		return false;
	}
	
	for (int i = 0; i < matrix->rows; i = i + 1) {
		int base = matrix->data[i][0];
		
		for (int j = 1; j < matrix->columns; j = j + 1) {
			int potencia = 1;
			for (int k = 0; k < j; k = k + 1) {
				potencia *= base;
			}
			if (matrix->data[i][j] != potencia) {
				return false;
			}
		}
	}
	return true;
}//end verifica_potencias()

void method_08(void){
	//identificar
	IO_id("Method_08 - Verificar Potencias por linha.\n");
	//definir dados
	ref_int_Matrix matrix = freadintMatrix("MATRIZ3.TXT");
	//chamar funcao para verificar potencias nas linhas
	bool result = verifica_potencias(matrix);
	if (result) {
		printf("A matriz possui potencias por linha.\n");
	} else {
		printf("A matriz nao possui potencias por linha.\n");
	}
	//liberar espaco
	free_int_Matrix(matrix);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_08()

/* -- Aluna: Rayssa Mell de Souza Silva 
-- Matricula: 860210 
Method_09 - Verificar potencias por coluna
*/

//funcao para verificar potencia por coluna
bool potenciasColuna(ref_int_Matrix matrix) {
	if (matrix->columns < 2) {
		return false;
	}
	
	for (int j = 0; j < matrix->columns; j = j + 1) {
		int base = matrix->data[0][j];
		
		for (int i = 1; i < matrix->rows; i = i + 1) {
			int potencia = 1;
			for (int k = 0; k < i; k = k + 1) {
				potencia *= base;
			}
			if (matrix->data[i][j] != potencia) {
				return false;
			}
		}
	}
	return true;
}//end verifica_potencias()

void method_09(void){
	//identificar
	IO_id("Method_09 - Verificar Potencias por coluna.\n");
	//definir dados
	ref_int_Matrix matrix = freadintMatrix("MATRIZ3.TXT");
	//chamar funcao para verificar potencias nas linhas
	bool result = potenciasColuna(matrix);
	if (result) {
		printf("A matriz possui potencias por coluna.\n");
	} else {
		printf("A matriz nao possui potencias por coluna.\n");
	}
	//liberar espaco
	free_int_Matrix(matrix);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_09()

/* -- Aluna: Rayssa Mell de Souza Silva 
   -- Matricula: 860210 
   Method_10 - Calcular e Comparar precos
*/

//struct para dados dos supermecados
typedef struct {
	char nome[50];
	int quant;
	int codigo;
	double preco_produto;
} Supermercado;

//funcao para ler arquivo
int lerArquivo(Supermercado *supermercados, chars fileName){
	FILE *arquivo = fopen(fileName, "rt");
	int x = 0;
	
	fscanf(arquivo, "%d", &supermercados->quant);
	
	while(!feof(arquivo) && x < supermercados->quant){
		fscanf(arquivo, "%s %d %f", &supermercados[x].nome, &supermercados[x].codigo, &supermercados[x].preco_produto);	
		x = x + 1;
	}
	
	fclose(arquivo);
	return 0;
}//end lerArquivo()

//funcao para calcular preco medio
double calcularPrecoMedio(Supermercado *supermercados){
	double soma_precos = 0.0;
	
	for (int i = 0; i < supermercados->quant; i = i + 1) {
		soma_precos += supermercados[i].preco_produto;
	}
	
	return soma_precos / supermercados->quant;
}//end calcularPrecoMedio()

//funcao para mostrar os precos inferiores a media
void inferioresMedia(Supermercado *supermercados, double media) {
	int contador = 0;
	
	printf("Supermercados com precos inferiores a media (%.2lf):\n", media);
	for (int i = 0; i < supermercados->quant; i++) {
		if (supermercados[i].preco_produto < media) {
			printf("Nome: %s, Codigo: %d, Preco: %.2lf\n", supermercados[i].nome, supermercados[i].codigo, 
														   supermercados[i].preco_produto);
			contador++;
			if (contador == 2) {
				printf("%s", supermercados[i].nome);
			}
		}
	}
}//end inferioresMedia()

void method_10(void){
	//identificar
	IO_id("Method_10 - Calcular preco de produto.\n");
	//definir dados
	Supermercado supermercados[4];
	lerArquivo(supermercados, "DADOS3.TXT");
	double media_precos = calcularPrecoMedio(supermercados);
    inferioresMedia(supermercados, media_precos);
	//encerrar
	IO_pause("\nPressione ENTER para continuar.\n");
}//end method_10()

int main(){
	int opcao = 0;
	printf ( "%s\n", "R02 - Programa = v0.0" );
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


/* --------------Registro de Resultados --------------------------
R02 - Programa = v0.0
Autor: Rayssa Mell de Souza Silva
Matricula: 860210


-----> Method_01 - Determinar ordem decrescente.

Arquivo de leitura: DADOS1.TXT
Dados gravados no arquivo DECRESCENTE.TXT

-----> Method_02 - Inverter arranjo.

Arquivo de leitura: DECRESCENTE.TXT
Dados gravados no arquivo INVERTIDOS.TXT

-----> Method_03 - Calcular Mediana e Moda.

Aquivo de leitura: DADOS1.TXT

-- Saída:
Mediana = 3.00
Moda = 2


-----> Method_04 - Elementos comuns em arranjos.

Arquivos de leitura: DADOS1.TXT e DADOS2.TXT
Dados gravados no arquivo FILTRADOS.TXT


-----> Method_05 - Cadeia de Caracteres.

Arquivos de leitura: BINARIOS1.TXT

-- Saída: 
0: 0
1: 11
2: 0
3: 8


-----> Method_06 - Matriz Tridiagonal Crescente.

Arquivos de leitura: MATRIZ1.TXT

-- Entrada:

Digite um valor para definir a matriz: 4

-- Saída:

Matriz1.txt:
1       2       3
4       5       6
7       8       9

Matriz Tridiagonal Crescente:
1       2       0       0
3       4       5       0
0       6       7       8
0       0       9      10

Gravado no arquivo MATRIZ2.TXT

-----> Method_07 - Matriz Tridiagonal Decrescente.

Arquivos de leitura: MATRIZ1.TXT

-- Entrada:

Digite um valor para definir a matriz: 4

-- Saída:

Matriz1.txt:
1       2       3
4       5       6
7       8       9

Matriz Tridiagonal Crescente:
9      10       0       0
6       7       8       0
0       3       4       5
0       0       1       2


Gravado no arquivo MATRIZ4.TXT


-----> Method_08 - Verificar Potencias por linha.

Arquivos de leitura: MATRIZ3.TXT

A matriz nao possui potencias por linha.


-----> Method_09 - Verificar Potencias por coluna.

Arquivos de leitura: MATRIZ3.TXT

A matriz nao possui potencias por coluna.


-----> Method_10 - Calcular preco de produto.

Arquivo de leitura: o DADOS3.TXT:

-- Saída: 
Supermercados com precos inferiores a media (0.00):
Nome: MercadoA, Codigo: 101, Preco: 0.00

*/
