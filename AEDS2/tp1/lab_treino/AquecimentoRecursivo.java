import java.util.Scanner;

public class AquecimentoRecursivo {
    
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

    public static int contarMaiusculas(String palavra){
        return contarMaiusculas(palavra, 0);
    }
    
    public static int contarMaiusculas(String palavra, int i){
        int contador = 0;

        if(i == palavra.length()){
            contador = 0;
        } 
        else if(palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z'){
            contador = 1 + contarMaiusculas(palavra, i + 1);
        }
        else {
            contador = contarMaiusculas(palavra, i + 1);
        }
        return(contador);
    }
    
    public static void main(String[] args){
        String palavra;
        Scanner sc = new Scanner(System.in);
        int contador;
        
        palavra = sc.nextLine();

        while(isEquals(palavra,"FIM")){
            contador = contarMaiusculas(palavra, 0);
            System.out.println(contador);
            palavra = sc.nextLine();
        }
    }
}