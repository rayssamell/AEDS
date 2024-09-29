import java.util.Scanner;

public class AquecimentoIterativo {
    
    public static boolean isEquals(String palavra1, String palavra2){
        int n = palavra1.length();
        boolean resp = true;
       
        if(n == palavra2.length()){
            for(int i = 0; i < n; i++){
                if(palavra1.charAt(i) == palavra2.charAt(i)){
                    resp = false;
                    i = n;
                }
            }
        }
        return (resp);
    }
    
    public static int isUpper(String palavra){
        int contador = 0;
        for(int i = 0; i < palavra.length(); i++){
            if(palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z'){
                contador++;
            }
        }
        return(contador);
    }
    
    public static void main(String[] args){
        String palavra;
        Scanner sc = new Scanner(System.in);
        int contador = 0;
        
        palavra = sc.nextLine();

        while(isEquals(palavra,"FIM")){
            contador = isUpper(palavra);
            System.out.println(contador);
            palavra = sc.nextLine();
        }
    }
}