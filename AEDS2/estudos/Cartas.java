import java.util.Scanner;

public class Cartas {
    private int[] array;
    private int n;

    public Cartas(int tamanho){
        array = new int[tamanho];
        n = 0;
    }
    public void empilhar(int valor){
        if(n >= array.length) System.out.println("ERRO");

        array[n++] = valor;
    }
    public int desempilhar(){
        if(n == 0) System.out.println("ERRO");

        int valor = array[0];
        n--;
        for(int i=0; i < n; i++){
            array[i] = array[i+1];
        }
        return valor;
    }

    public void baralho(){
        int j = 0;
        int[] discarted = new int[n-1];
        while(n > 1){
            discarted[j++] = desempilhar();
            empilhar(desempilhar());

        }
        System.out.print("Discarded cards: ");
        for(int i=0; i < discarted.length; i++){
            System.out.print(discarted[i]);
            if(i < j - 1) {
                System.out.print(", ");
            }
        }
        System.out.println();
        System.out.println("Remaining card: "+ array[0]);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();

        while(d != 0){
            Cartas c = new Cartas(d);
            for(int i=0; i < d; i++){
                c.empilhar(i+1);
            }
            c.baralho();
            d = sc.nextInt();
        }
        sc.close();
    }
}
