/* Recuperacao_01 - Rayssa Mell de Souza Silva - 860210 */

#include<stdio.h>
#include<math.h>
#include "io.h"
#include <stdbool.h>
#include <string.h>

/* Method_01 - Rayssa Mell de Souza Silva - 860210*/

// funcao para somar divisores impares
int soma_divisores_impares(int x){
	//definir dados
	int soma = 0;
	int impar = 1;
	
	//testar condicao para impares menor ou igual x
	while(impar <= x){
		if(x % impar == 0){
			soma = soma + impar;
		}
		impar = impar + 2;
	}
	//retorna resultado
	return (soma);
}

void method_01(void){
	//identificar
	IO_id("\nMetodo_01 - Soma dos divisores impares.\n");
	//definir dados
	int n = 0;
	int x = 0;
	int resposta = 0;
	//ler dados
	n = IO_readint("\nDigite a quantidade: ");
	getchar();
	//testar condicao para n valores
	for(int y = 0; y < n; y = y + 1){
		x = IO_readint("\nValor: ");getchar();
		//chamar funcao
		resposta = soma_divisores_impares (x);
		//exibir resposta
		printf("Soma dos divisores impares de %d = %d\n", x, resposta);
	}	
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_01()

/* Method_02 - Rayssa Mell de Souza Silva - 860210*/

//funcao bool para testar se o numero eh primo
bool ehPrimo(int x){
	//definir dados
	int impar = 1, cont = 0;
	bool result = false;
	
	// se x for 2
	if(x == 2){
		cont = 2;
	}
	else{
		// se x for maior que 0 e impar 
		if(x > 0 && x % 2 != 0){
			while(impar <= x){
				if(x % impar == 0){
					cont = cont + 1;
				}
				impar = impar + 2;
			}
		}
	}
	//se dividir somente por 1 e pelo proprio numero eh primo
	result = (cont == 2);
	return(result);
}

void method_02(void){
	//identificar
	IO_id("\nMethod_02 - Identificar numeros primos.");
	//definir dados
	int n = 0, x = 0, y = 0;
	//ler dado
	n = IO_readint("\nDigite a quantidade: ");getchar();
	//testar condicao para n valores
	for(y = 0; y < n; y = y + 1){
		x = IO_readint("\nValor: ");
		getchar();
		
		//chamar funcao para identificar se o numero eh primo
		if(ehPrimo(x)){
			printf("\n%d eh primo.\n", x);
		}
		else{
			printf("\n%d nao eh primo.\n", x);
		}
	}
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_02()

/* Method_03 - Rayssa Mell de Souza Silva - 860210*/

//funcao para identificar o simbolo por caractere
int identificar_simbolo(char caractere) {
	switch(caractere) {
	case '&':
	case '|':
	case '!':
		return 1; // operador lógico
		break;
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return 2; // operador aritmético
		break;
	case '>':
	case '<':
	case '=':
		return 3; // operador relacional
		break;
	case ' ':
	case '.':
	case ',':
	case ';':
	case ':':
	case '_':
		return 4; // separador
		break;
	default:
		return 0; // outro símbolo qualquer
		break;
	}
}

void method_03(void){
	//identificar
	IO_id("\nMethod_03 - Identificar Simbolo.");
	//definir dado
	chars cadeia = IO_new_chars(STR_SIZE);
	//ler dado
	cadeia = IO_readstring("\nDigite uma cadeia de caracteres: ");
	getchar();
	
	printf("Resultados:\n");
	//testar condicao para menor que o tamanho da cadeia
	for(int i = 0; i < strlen(cadeia); i = i + 1) {
		//chamar funcao
		int tipo = identificar_simbolo(cadeia[i]);
		//return 1
		if(tipo == 1){
			printf("Operador Logico: [%c]\n", cadeia[i]);
		}
		//return 2
		if(tipo == 2){
			printf("Operador Aritmetico: [%c]\n", cadeia[i]);
		}
		//return 3
		if(tipo == 3){
			printf("Operador Relacional: [%c]\n", cadeia[i]);
		}
		//return 4
		if(tipo == 4){
			printf("Separador: [%c]\n", cadeia[i]);
		}
		//return 5
		if(tipo == 0){
			printf("\nOutro");
		}
	}
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_03()

/* Method_04 - Rayssa Mell de Souza Silva - 860210*/

// funcao para identificar maiuscula, minuscula, numero e outra caractere
int identificar(char caractere){
	if (caractere >= 'A' && caractere <= 'Z') {
		return 1; // Se for maiuscula
	} 
	else {
		if (caractere >= 'a' && caractere <= 'z') {
		return 2; // Se for minuscula
	    } 
        else {
			if (caractere >= '0' && caractere <= '9') {
			return 3; // Se for numero
			}
     		else {
				return 4; // Se for outro caractere
			}
		}
	}
}

void method_04(void){
	//identificar
	IO_id("\nMethod_03 - Contar maisculas, minusculas, digitos e simbolos.");
	//definir dados
	chars cadeia = IO_new_chars(STR_SIZE);
	int maiusculas = 0, minusculas = 0;
	int digitos = 0, simbolos = 0;
	//ler dado
	cadeia = IO_readstring("\nDigite uma cadeia de caracteres: ");
	getchar();
	//teste para i menor que tamanho da cadeia
	for (int i = 0; i < strlen(cadeia); i++) {
		//identificar caractere e contar
		switch (identificar(cadeia[i])) {
		case 1:
			maiusculas++;
			break;
		case 2:
			minusculas++;
			break;
		case 3:
			digitos++;
			break;
		default:
			simbolos++;
			break;
		}
	}
	//exibir resultados
	printf("\nContagem: \n");
	printf("Maiusculas: %d\n", 	maiusculas);
	printf("Maiusculas: %d\n", 	minusculas);
	printf("Maiusculas: %d\n", 	digitos);
	printf("Maiusculas: %d\n", 	simbolos);
	
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
} //end method_04()

/* Method_05 - Rayssa Mell de Souza Silva - 860210*/

//funcao para calcular media dos menores que o intervalo
double media_menores(double array[], int n, double inferior){
	//definir dados
	double soma = 0.0;
	int cont = 0;
	//testar para y menor que quantidade (n)
	for(int y = 0; y < n; y = y + 1){
		if(array[y] < inferior){
			soma = soma + array[y];
			cont = cont + 1;
		}
	}
	double media = soma / cont;
	return (media);
}

//funcao para media de valores maiores que o intervalos
double media_maiores(double array[], int n, double superior){
	//definir dados
	double soma = 0.0;
	int cont = 0;
	//testar y menor que quantidade(n)
	for(int y = 0; y < n; y = y + 1){
		if(array[y] > superior){
			soma = soma + array[y];
			cont = cont + 1;
		}
	}
	double media = soma / cont;
	return (media);
}

//funcao para media de valores dentro do intervalo
double media_intervalo(double array[], int n, double inferior, double superior){
	double soma = 0.0;
	int cont = 0;
	for(int y = 0; y < n; y = y + 1){
		if(array[y] > inferior && array[y] < superior){
			soma = soma + array[y];
			cont = cont + 1;
		}
	}
	double media = soma / cont;
	return (media);
}

//funcao para identificar maior valors
double maiorValor(double a, double b, double c ){
	//definir dado
	double maior = 0.0;
	
	// maior valor = a
	if(a > b && a > c){
		maior = a;	
	}
	else{
		//maior valor = b
		if(b > a && b > c){
			maior = b;
		}
		else{
			//maior valor = c
			maior = c;
		}
	}
	return maior;
}

void method_05(void){
	//identificar
	IO_id("\nMethod_05 - Media dos valores menores, maiores e dentro do intervalo.");
	//definir dados
	int n = 0;
	double x = 0.0;
	double inferior = -17.25;
	double superior = 93.75;
	//ler dados
	n = IO_readint("\nDigite um valor inteiro: ");
	//definir arranjo
	double array[n];
	
	//repetir enquanto y for menor que a quantidade (n))
	for(int y=0; y < n; y = y + 1){
		printf("\nValor real: ");
		scanf("%lf", &x);
		getchar();
		//guardar no arranjo
		array[y] = x;
	}
	//chamar funcao para identificar e calcular media
	double mediaMenores = media_menores(array, n, inferior);
	double mediaMaiores = media_maiores(array, n, superior);
	double mediaIntervalo = media_intervalo(array, n, inferior, superior);
	
	//media dos menores que o intervalo
	if (mediaMenores != 0) {
		printf("\nMedia dos valores menores que %.2lf: %.2lf", inferior, mediaMenores);
	} 
	//media maiores que o intervalo
	if (mediaMaiores != 0) {
		printf("\nMedia dos valores maiores que %.2lf: %.2lf", superior, mediaMaiores);
	} 
	//media dos valores dentro do intervalo
	if (mediaIntervalo != 0) {
		printf("\nMedia dos valores entre %.2lf e %.2lf: %.2lf", inferior, superior, mediaIntervalo);
	}
	
	//chamar funcao para identificar maior media e exibir valors
	double maior = maiorValor(mediaMenores, mediaMaiores, mediaIntervalo);
	printf("\n");
	printf("\nMaior media: %.2lf", maior);
	
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//ende method_05()

/* Method_06 - Rayssa Mell de Souza Silva - 860210 */

//funcao para calcular inverso, cubo dos imapres e somar
double soma_cubos(int a, int b, int x){
	//definir dados
	double soma = 0.0;
	double inverso = 0.0;
	//testar para x diferente de 0
	if (x != 0) {
		//dentro do intervalo e impar
		if(x > a && x < b && x % 2 != 0){
			//calcular cubo e inverso
			inverso = 1 / pow(x,3);
			soma = soma + inverso;
		}
	}
	//retornar soma
	return (soma);
}

void method_06(void){
	//identificar
	IO_id("\nMethod_06 - Soma dos inversos dos cubos dos impares. ");
	//definir dados
	int a = 0, b = 0;
	int x = 0;
	double soma = 0.0;
	//ler dados para definir intervalo
	a = IO_readint("\nDigite um valor: ");
	getchar();
	b = IO_readint("\nDigite outro valor: ");
	getchar();
	
	//enquanto x for diferente de -1
	do {
		printf("Digite um valor (-1 para sair): ");
		scanf("%d", &x);
		getchar();
		
		// x diferente de 0 chamar funcao
		if (x != 0) {
			soma += soma_cubos(a, b, x);
		}
	// testar enquanto x diferente de -1 e no intervalo
	} while (x != -1 && (x > a && x < b));
	//exibir resultado
	printf("\nResultado: %.4lf", soma);
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_06()

/* Method_07 - Rayssa Mell de Souza Silva - 860210*/

//funcao para verificar intervalo
int intervalo(double a, double b, double x) {
	if (x != 0) {
		if (x > a && x < b) {
			return 1; // dentro do intervalo
		}
		if (x < a) {
			return 2; // abaixo do intervalo
		}
		return 3; // acima do intervalo
	}
	return 0; 
}

void method_07(void){
	//identificar
	IO_id("\nMethod_07 - Identificar valor dentro do intervalo, abaixo e acima. ");
	//definir dados
	float a = 0.0, b = 0.0;
	float x = 0.0;
	int cont_d = 0, cont_f_acima = 0, cont_f_abaixo = 0;
	
	//ler dados
	a = IO_readfloat("\nDigite um valor: ");
	getchar();
	b = IO_readfloat("\nDigite outro valor: ");
	getchar();
	
	//testar se a diferente de b 
	if( a != b){
		do {
			printf("Digite um valor (0 para sair): ");
			scanf("%f", &x);
			getchar();
			//chamar funcao para verificar valor
			int identificar = intervalo(a,b,x);
			//dentro do intervalo
			if(identificar == 1){
				cont_d = cont_d + 1;
			}
			else{
				//abaixo do intervalo
				if(identificar == 2){
					cont_f_abaixo = cont_f_abaixo + 1;
				}
				//acima do intervalo
				if(identificar == 3){
					cont_f_acima = cont_f_acima + 1;
				}
			}
		//testar enquanto diferente de 0	
		} while (x != 0);
		
		//valores dentro do intervalo
		printf("\nDentro do intervalo: %d\n", cont_d );
		// somar valores
		int soma = cont_d + cont_f_abaixo + cont_f_acima;
		
		//porcentagem dos valores acima e abaixo de intervalo
		if (soma != 0) {
			float porcentagem_abaixo = ((float)cont_f_abaixo * 100) / soma;
			float porcentagem_acima = ((float)cont_f_acima * 100) / soma;
			
			printf("\nPorcentagem abaixo do intervalo: %.2f%%\n", porcentagem_abaixo);
			printf("Porcentagem acima do intervalo: %.2f%%\n", porcentagem_acima);
		} 
		else {
			printf("\nNenhum valor foi inserido.\n");
		}	
	}
	//testar se os valores sao iguais
	else{
		printf("\nERRO: Valores iguais.");
	}
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_07()

/* Method_08 - Rayssa Mell de Souza Silva - 860210*/

//funcao para verificar se eh crescente
double crescente(double x, double y, double z){
	if (x < y && y < z) {
		return x;
	}
	return 0.0;
}

//funcao para verificar se eh decrescente
int decrescente(double x, double y, double z){
	if (x > y && y > z ) {
		return z;
	}
	return 0.0;
}

//funcao para verificar se eh maior
double maior(double x, double y, double z){
	if (x > y && x > z) {
		return x;
	} else{ 
		if (y > x && y > z) {
		return y;
	} 	else{ 
			if (z > x && z > y) {
			return z;
			}
		}
	}
	return 0.0;
}


//funcao para verificar se eh menor
double menor(double x, double y, double z){
	if (x < y && x < z) {
		return x;
	} else {
		if (y < x && y < z) {
		return y;
	} else{ 
		if (z < x && z < y) {
		return z;
		}
	}
	}
	return 0.0;
}

void method_08(void){
	//identificar
	IO_id("\nMethod_08");
	//definir dados
	double x = 0.0, y = 0.0, z = 0.0;
	//ler dados
	x = IO_readdouble("\nDigite um valor real: ");
	getchar();
	y = IO_readdouble("\nDigite um valor real: ");
	getchar();
	z = IO_readdouble("\nDigite um valor real: ");
	getchar();
	
	//testar condicoes para funcoes definidas
	if(crescente ( x, y, z )){
		printf("\n%.2lf, %.2lf e %.2lf estao em ordem crescente.", x, y, z);
	}
	else{
		if(decrescente ( x, y, z )){
			printf("\n%.2lf, %.2lf e %.2lf estao em ordem decrescente.", x, y, z);
		}
		else{
			double maiorValor = maior(x, y, z);
			double menorValor = menor(x, y, z);
			printf("\nValores nao estao em ordem crescente ou decrescente.");
			printf("\nMaior valor: %.2lf", maiorValor);
			printf("\nMenor valor: %.2lf", menorValor);
		}
	}
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_08()

/* Method_09 - Rayssa Mell de Souza Silva - 860210*/

//funcao para ordem crescente
bool ordemCrescente(char x, char y, char z) {
	return (x < y && y < z);
}

//funcao paraordem decrescente
bool ordemDecrescente(char x, char y, char z) {
	return (x > y && y > z);
}

//funcao para sucessor
bool sucessor(char x, char y){
	return ((int)y - 1 == (int)x);

}

void method_09(void){
	//identificar
	IO_id("\nMethod_09 - Identificar Ordem dos Valores.");
	// definir dados
	char x;
	char y;
	char z;
	// ler dados
	x = IO_readchar("\nDigite um caractere: ");
	getchar();
	y = IO_readchar("\nDigite um caractere: ");
	getchar();
	z = IO_readchar("\nDigite um caractere: ");
	getchar();
	
	//testar com funcao
	if (ordemCrescente(x, y, z)) {
		printf("\nOs caracteres estao em ordem crescente.\n");
	} else {
		if (ordemDecrescente(x, y, z)) {
			printf("\nOs caracteres estao em ordem decrescente.\n");
		}
		else{
			printf("\nNao estao em ordem crescente ou decrescente.");
			if (sucessor(x, y)) {
				printf("\n%c eh sucessor de %c na ordem alfabetica.\n", y, x);
			} 
		}
	}
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_09()

/* Method_10 - Rayssa Mell de Souza Silva - 860210*/

//funcao para compara cadeias
int comparar(chars x, chars y) {
	return strcmp(x, y);
}

//funcao para identificar menor cadeia
chars menorCadeia(chars x, chars y, chars z){
	chars menor = x;
	if (comparar(y, menor) < 0) {
		menor = y;
	}
	
	if (comparar(z, menor) < 0) {
		menor = z;
	}
	return menor;
}

//funcao para identificar maior cadeia
chars maiorCadeia(chars x, chars y, chars z){
	chars maior = x;
	if (comparar(y, maior) > 0) {
		maior = y;
	}
	
	if (comparar(z, maior) > 0) {
		maior = z;
	}


	return maior;
}

void method_10(void) {
	//identificar
	IO_id("\nMethod_10 - Comparar cadeias de caracteres.");
	//definir dados
	chars x = IO_new_chars(STR_SIZE);
	chars y = IO_new_chars(STR_SIZE);
	chars z = IO_new_chars(STR_SIZE);
	
	// ler dados
    x = IO_readstring("\nDigite uma cadeia de caracteres: ");
    y = IO_readstring("\nDigite uma cadeia de caracteres: ");
    z = IO_readstring("\nDigite uma cadeia de caracteres: ");
	
	// comparar as cadeias de caracteres
	int resultado1 = comparar(x, y);
	int resultado2 = comparar(y, z);
	
	// verificar a ordem alfabetica
	if (resultado1 > 0 && resultado2 > 0) {
		printf("\nAs cadeias estao em ordem alfabetica decrescente.\n");
	} else if (resultado1 < 0 && resultado2 < 0) {
		printf("\nAs cadeias estao em ordem alfabetica crescente.\n");
	} else {
		printf("\nAs cadeias nao estao em ordem alfabetica crescente nem decrescente.\n");
		
	   //menor e a maior cadeia de caracteres
		printf("\nMenor cadeia de caracteres: %s\n", menorCadeia(x,y,z));
		printf("\nMaior cadeia de caracteres: %s\n", maiorCadeia(x,y,z));
	}
	//encerrar
	printf("\n");
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_10()

int main(){
	int opcao = 0;
	printf ( "%s\n", "Exemplos 0800 - Programa = v0.0" );
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

/* Saídas e Resultados - Rayssa Mell de Souza Silva - 860210

--> Method_01
Calcular soma dos divisores impares do numero inserido
n = 5
   Entrada  -> Saída
{ Valor:  7 -> Soma = 8}
{ Valor: 25 -> Soma = 31}
{ Valor: 16 -> Soma = 1}
{ Valor: 30 -> Soma = 24}
{ Valor: 17 -> Soma = 18}

--> Method_02
Identificar se o numero eh ou nao primo
n = 5
   Entrada -> Saída
{ Valor: 2  ->  2 eh primo.}
{ Valor: 15 -> 15 nao eh primo.}
{ Valor: 5  -> 5 eh primo.}
{ Valor: 3  -> 3 eh primo.}
{ Valor: 30 -> 30 nao eh primo.

--> Method_03
Entrada: &|!+-/%*<>=:,;:

Saída: 
Operador Logico: [&] [|]  [!]
Operador Aritmetico: [+]  [-]  [*]  [/]  [%]
Operador Relacional: [<]  [>]  [=]
Separador: [:]  [,]  [;]  [:]

--> Method_04
Contar maisculas, minusculas, digitos e simbolo em uma cadeia de caracteres
Entrada: ABCDefgh1234/-*+><
Saída:
Maiusculas: 4
Maiusculas: 4
Maiusculas: 4
Maiusculas: 6

--> Method_05
Calcular media de valores maiores, menores e dentro do intervalo, mostrar maior media

Dados de Entrada:
n = 6
{-21.44, -18.25, 15.26, 28.52, 96.44, 98.53}
Saida: 
Menores que -17.25: -19.84
Maiores que 93.75: 97.48
Media dos valores entre -17.25 e 93.75: 21.89

Maior media: 97.48

--> Method_06
Calcular soma do inverso do cubo dos impares

Entrada: 
{5,15} - Intervalo definido
{6,7,8,9,10,11} -1 para parar
Saida:
Resultado: 0.0050

--> Method_07
Identificar se o valor esta acima, abaixo ou dentro do intervalo
Entrada:
{5,22} - Intervalo definido
{7, 9, 28, 45, 13, 25, 2, 3) 0 para parar

Saída:
Dentro do intervalo: 3
Porcentagem abaixo do intervalo: 25.00%
Porcentagem acima do intervalo: 37.50%

--> Method_08
Identificar ordem dos valores ou maior e menor
Entrada: 
{2.45, 3.26,8.27}
{6.25, 4.42, 2.27}
{8.87, 15.21, 6.42}

Saida: 
2.45, 3.26 e 8.27 estao em ordem crescente.

6.25, 4.42 e 2.27 estao em ordem decrescente.

Valores nao estao em ordem crescente ou decrescente.
Maior valor: 15.210000
Menor valor: 6.420000

--> Method_09
Identificar ordem crescente, decrescente ou sucessor

Entrada: 
- {a,b,c}
- {c,b,a}
- {n,m,a}

Saida:
 - Os caracteres estao em ordem crescente.
 - Os caracteres estao em ordem decrescente.
 - Nao estao em ordem crescente ou decrescente.
   n eh sucessor de m na ordem alfabetica.

--> Method_10
Identificar se a cadeia esta na ordem crescente ou decrescente, ou maior e menor cadeia

Entrada:
{abcde, efghi, lmnopq}
Saída:
As cadeias estao em ordem alfabetica crescente.

Entrada:
{rstuv, mnopq, ijkl}
Saida:
As cadeias estao em ordem alfabetica decrescente.

Entrada:
{abcdefg, zwxy, lmnopq}
Saida:
As cadeias nao estao em ordem alfabetica crescente nem decrescente.
Menor cadeia de caracteres: abcdefg
Maior cadeia de caracteres: zwxy

*/
