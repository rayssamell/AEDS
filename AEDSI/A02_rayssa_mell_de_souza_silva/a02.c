/* Refacao 02 - Rayssa Mell de Souza Silva - 860210 */

#include <stdio.h>
#include<string.h>
#include <stdlib.h>

/* QUESTAO_01

Resposta: a.) 2

*/

/* QUESTAO_02

Resposta: b.) "igioiiia"

*/

/* QUESTAO_03

x = 0  -> m[0][2]  = Grau
x = 1  -> 'Amarelo' if ('A' < m[x][0][0] && m[x][0][0] <= 'Z') = false
x = 2  -> m[2][2]  = Lila

Resposta: c.) Grau   Lila

*/

/* QUESTAO_04 

Resposta: d.) chcltd

*/

/* QUESTAO_05

p = q_05 (1, 4, q_05(2, 3, p));  
a l e g r i a = 1. l   4. r  /  2. e   3. g
c = p[1]  p[1] = p[4]   p[4] = c
c = l     p[1] = r      p[4] = l
a r g e l i a 

p = q_05 (2, 3, q_05(1, 4, p));
a r g e l i a = 2. g   3. e  /  1. l  4. r 
c = p[2]  p[2] = p[3]   p[3] = c
c = g     p[2] = e      p[3] = g
a l e g r i a

Resposta: a.) "argelia", "alegria";
*/

/* QUESTAO_06 */

//funcao para testar se o valor eh primo
void calcularNumero(char *nome){
	int soma = 0;
	for(int i = 0; i < strlen(nome); i = i + 1){
		if(nome[i] == 'A' || nome[i] == 'J' || nome[i] == 'S'){
			soma += 1;
		}
		else if(nome[i] == 'B' || nome[i] == 'K' || nome[i] == 'T'){
			soma += 2;
		}
		else if(nome[i] == 'C' || nome[i] == 'L' || nome[i] == 'U'){
			soma += 3;
		}
		else if(nome[i] == 'D' || nome[i] == 'M' || nome[i] == 'V'){
			soma += 4;
		}
		else if(nome[i] == 'E' || nome[i] == 'N' || nome[i] == 'W'){
			soma += 5;
		}
		else if(nome[i] == 'F' || nome[i] == 'O' || nome[i] == 'Y'){
			soma += 6;
		}
		else if(nome[i] == 'G' || nome[i] == 'P' || nome[i] == 'X'){
			soma += 7;
		}
		else if(nome[i] == 'H' || nome[i] == 'Q' || nome[i] == 'Z'){
			soma += 8;
		}
		else if(nome[i] == 'I' || nome[i] == 'R'){
			soma += 9;
		}
	}
	int p = soma / 10;
	int u = soma % 10;
	int calcular = p + u;
	if(soma == 11){
		printf("11");
	}
	else if(soma == 22){
		printf("22");
	}
	else{
		printf("%d", calcular);
	}
}

void p_06(void){
	char *nome;
	
	nome = (char*)malloc(80 * sizeof(char));
	
	printf("Digite um nome: ");
	fgets(nome, 80, stdin); getchar();
	
	calcularNumero(nome);
}

/* QUESTAO_07 */
struct Dias {
	int dias[3];
	struct Data {
		int dia;
		int mes;
		int ano;
	} data[3];
};

void p_07(void){
	struct Dias d;
	int d1 = 9876, d2 = 8967, d3 = 6789;

	d.dias[0] = d1 % 365; 
	d.dias[1] = d2 % 365;
	d.dias[2] = d3 % 365;
	
	if(d.dias[0] > d.dias[1] && d.dias[0] > d.dias[2]){
		printf("Pessoa 1 primeiro.");
	}
	else if(d.dias[0] < d.dias[1] && d.dias[1] > d.dias[2]){
		printf("Pessoa 2 primeiro.");
	}else{
		printf("Pessoa 3 primeiro.");
	}
}

/* QUESTAO_08 */
void p_08(void){
	FILE *arquivo = fopen("DADOS.TXT", "rt");
	FILE *n1_arquivo = fopen("PARES.TXT", "wt");
	FILE *n2_arquivo = fopen("IMPARES.TXT", "wt");
	
	int x = 0;
	while(! feof(arquivo)){
		fscanf(arquivo, "%d", &x);
		if(x % 2 == 0){
			fprintf(n1_arquivo, "%d\n", x);
		}else{
			fprintf(n2_arquivo, "%d\n", x);
		}	
	}
	fclose(arquivo);
	fclose(n1_arquivo);
	fclose(n2_arquivo);
}

int main(){
	
	int opcao = 0;
	printf ( "%s\n", "A02 - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
	
	do{
		printf("\n%s\n", "\nOpcoes: ");
		printf("\n%s", "0 - Terminar");
		printf("\n%s", "1 - Metodo_01	2 - Metodo_02	3- Method_03");
		
		printf("\n%s", "\nOpcao = ");
		scanf("%d", &opcao);
		getchar();
		// para mostrar a opcao lida
		printf ( "\n%s%d", "Opcao =  ", opcao );
		getchar();
		//testar valor
		switch (opcao) {
		case 1:
			p_06();
			break;
		case 2:
			p_07();
			break;
		case 3:
			p_08();
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



