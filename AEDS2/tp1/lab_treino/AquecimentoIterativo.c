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

int isUpper(char palavra[]){
    int contador = 0;
    for(int i = 0; i < str_len(palavra); i++){
        if(palavra[i] >= 'A' && palavra[i] <= 'Z'){
            contador++;
        }
    }
    return(contador);
}

int main(){
    char palavra[500];
    int contador = 0;
    
    scanf(" %[^\n]", palavra);  
    
    while(str_cmp(palavra, "FIM") != 0){
        contador = isUpper(palavra);
        printf("%d\n", contador);
        
        scanf(" %[^\n]", palavra);
    }

    return 0;
}