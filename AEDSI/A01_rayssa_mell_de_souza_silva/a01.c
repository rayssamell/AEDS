/* Refacao - Rayssa Mell de Souza Silva - 860210*/

#include <stdio.h>
#include<string.h>
#include "io.h"

/* QUESTAO_01

Saida: printf("%d", f_01("5aP4+0_8r4nK0"));
Resposta: -1 
Resolucao = 
para t = -1     {5,4,0,8,4} = y = y -1 = -6                 
para r e s = 1  {aPrnK} = y = y + 1 = 5
w = {+_};

*/

/* QUESTAO_02
Saida: printf("\nf_02 (35,75) = %d\n", f_02(35,75));
Resposta: 3
Resolucao =
nao entra em nenhuma condicao, passa para retorno
return ((b-1) % (a-1)/2);
75-1 = 74      35 - 1 = 34
74 % 34 = 6 / 2 = 3
*/

/* QUESTAO_03
Resposta e) Outra;
Resolucao = 
--> Para primeira repeticao a saida eh {3,5,7,9,11}
--> Para segunda ser igual x deveria iniciar com 3 
x = 3; x <= 15; x = x + 3
(4*x+6)/6 = {3,5,7,9,11};
*/

/* QUESTAO_04 
Resposta = b) 1 1 2 5 7
x = [1] 
y = [1]
v = 1 + 1 = [2]
w = 1 + 1 + 2 + 1 = [5]
x = v y = w
2 + 5 = [7]
*/

/* QUESTAO_05
Resposta e) Outra
Resolucao = 
--> 0  <= 4   s[0] == s[4]
--> 1 <= 3    s[1] == s[3]
--> 2 <= 2    s[2] == s[2]
x = 3 // y = 1
return 3 - 1 + 6 - 6 = 2
*/

/* QUESTAO_06 */

//funcao para testar se o valor eh primo
int ehPrimo(int valor){
	int impar = 1, cont = 0;
	
	//se for 2 eh primo
	if(valor == 2) {
		return 2;
	}
	else{
		//se nao for 2 testar se eh impar para descobrir se eh primo
		if(valor % 2 != 0){
			while(impar <= valor){
				if(valor % impar == 0){
					cont =  cont + 1;
				}
				impar = impar + 2;
			}
		}
	}
	// se dividir por 2 numeros somente o valor eh primo
	if(cont == 2){
		return valor;
	}
	
	return 0;
}

void p_06(void){
	//definir dados
	int num = 11, cont = 0;
	int p1= 0, p2 = 0;
	int parSheldon = 0, primo = 0;
	
	//testar intervalo 11 a 99
	while(num <= 99){
		//verifica se eh primo
		primo = ehPrimo(num);
		//calcula o par de sheldon do valor
		p1 = (primo % 10) * 10;
		p2 = primo / 10;
		parSheldon = p1 + p2;
		// se o par de sheldon for primo imprime
		if(ehPrimo(parSheldon)){
			//teste para evitar repeticao de valores
			if(primo < parSheldon){
				printf("\n%d e %d\n", primo, parSheldon);
				cont = cont + 1;
			}
		}
		num = num + 2;
	}
	printf("\nHa %d numeros de sheldon no intervalo", cont);
}

/* QUESTAO_07 */
int f_07(char p[]){
	int x = 0, temT=0, temU=0;
	int naoUT = 0;
	
	for( x = 0; x < strlen(p); x = x + 1){
		
		if(p[x]=='T'){
		    temT = 1;
		}

		if(p[x]=='U'){
			temU = 1;
		}
		else{
			if(p[x]!= 'T' && p[x]!= 'U'){
				naoUT = 1;
			}
		}
	}
	if(temT && !(temU)){
		printf("DNA:2");
	}
	else{
		if(temU != temT){
			printf("RNA: 1");
		}
		else{
			if(naoUT){
				printf("0");
			}
			else{
				if(temT && temU){
					printf("-1");
				}
			}
		}
	}
	return 0;
}

void p_07(void){
	char p[] = "TACAGATA";
	f_07(p);
}

/* QUESTAO_08 */
bool isDigit(chars cadeia){
	bool result = true; 
	int tamanho = strlen(cadeia);
	int x = 0;
	while (x < tamanho && result) {
		 if (!(cadeia[x] >= '0' && cadeia[x] <= '9')){ 
			result = false; 
		}
		x = x + 1;
	}
	return result;
}

bool testar(chars cadeia) {
	int soma_quadrado = 0, soma_cubos = 0;
	
	for(int i = 0; i < strlen(cadeia); i = i + 1) {
		//testando se eh digito
		if (cadeia[i] > '0' && cadeia[i] <= '9') {
			int digito = cadeia[i] - '0';// para passar para inteiro
			
			// calculando soma dos quadrados
			soma_quadrado += digito;
			
			// Calculando soma dos cubos
			int cubo = digito;
			for(int x = 1; x < 3; x = x + 1) {
				int z = 0;
				for(int y = 0; y < digito; y = y + 1) {
					z += cubo;
				}
				cubo = z;
			}
			soma_cubos += cubo;
		}
	}
	
	// calculando o quadrado da soma
	int quadrado = 0;
	for(int i = 0; i < soma_quadrado; i = i + 1) {
		for(int x = 0; x < soma_quadrado; x = x + 1) {
			quadrado = quadrado + 1;
		}
	}
	
	// verificando se a soma dos quadrados eh igual a soma dos cubos
	return quadrado == soma_cubos;
}

void p_08(void){
	chars cadeia = IO_new_chars(STR_SIZE);
	cadeia = IO_readstring("Digite uma cadeia de caracteres: ");

	if(isDigit(cadeia)){
		if (testar(cadeia)) {
			printf("\nA soma dos termos ao quadrado eh igual a cada termo ao cubo.\n");
		} else {
			printf("\nA soma dos termos ao quadrado nao eh igual a cada termo ao cubo.\n");
		}
	}
	else{
		printf("\nErro: Cadeia Alfanumerica");
	}
}

int main(){
	
	int opcao = 0;
	printf ( "%s\n", "Exercicios 0700 - Programa = v0.0" );
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
	


