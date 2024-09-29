import java.util.Scanner;

public class Ordenacao {
    // metodo para trocar valores de posicao
    public static void swap(String[] array, int i, int j){
        String temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    //metodo para mostrar arranjo
    public static void mostrar(String[] array){
        for(int i=0; i < array.length; i++){
            System.out.print(array[i]+ " ");
        }
        System.out.println();
    }
    //metodo para ordenar arranjo - Bubble Sort
    public static void ordenar(String[] array){
        //posicao de onde ocorreu o ultimo swap
        int lastSwap = array.length-1;
        for(int i=0; i < array.length-1; i++){
            int newSwap = -1; // swap
            for(int j=0; j < lastSwap; j++){
                if(array[j].length() < array[j+1].length()){  //comparando tamanho das strings
                    swap(array, j, j+1);// swap
                    newSwap = j; //guarda a posicao do swap
                }
            }
            if(newSwap == -1) i = array.length; // se nao tiver mais swap para
            else lastSwap = newSwap; // caso contrario guarda a posicao do ultimo swap que aconteceu
        }
    }
    //metodo principal
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        sc.nextLine(); //limpar quebra de linha

        if(n > 0){
           
            for(int i=0; i < n; i++){
                //le a frase
                String frase = sc.nextLine();
                // transforma a frase em um array de palavras
                String[] array = frase.split("\\s+"); // (\\s+) divide quando encontra um espaco em branco
                ordenar(array); //ordena o array de palavras em ordem descrescente de tamanho
                mostrar(array); //mostra o array ordenado
                //System.out.println();
            }
        }
        sc.close();
    }    
}
