#include <stdio.h>
#include <stdbool.h>

int str_len(char *palavra){
    int length = 0;
	while(*(palavra+length)){ 
		length++;
	}
	return(length);
}

bool str_cmp(char palavra1[], char palavra2[]){
    bool resp = true;
    int length = str_len(palavra1);

    if(length == str_len(palavra2)){
        for(int i = 0; i < length; i++){
            if(palavra1[i] == palavra2[i]){
               resp = false;
               i = length;
            } 
        }
    }
    return (resp);
}

int contarMaiusculas(char palavra[], int i){
    int contador = 0;
    int tamanho = str_len(palavra);
    
    if(i == tamanho){
        contador = 0;
    } 
    else if(palavra[i] >= 'A' && palavra[i] <= 'Z'){
        contador = 1 + contarMaiusculas(palavra, i + 1);
    }
    else {
        contador = contarMaiusculas(palavra, i + 1);
    }
    return(contador);
}

int main(){
    char palavra[500];
    int contador = 0;
    
    scanf(" %[^\n]", palavra);  
    
    while(str_cmp(palavra, "FIM") != 0){
        contador = contarMaiusculas(palavra, 0);
        printf("%d\n", contador);
        
        scanf(" %[^\n]", palavra);
    }

    return 0;
}