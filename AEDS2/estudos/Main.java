import java.util.Scanner;

public class Main {

    private static class Duendes {
        private String nome;
        private int idade;

        // Construtor
        public Duendes(String nome, int idade) {
            this.nome = nome;
            this.idade = idade;
        }

        // Métodos getters
        public String getNome() {
            return nome;
        }

        public int getIdade() {
            return idade;
        }

        @Override
        public String toString() {
            return nome + " " + idade;
        }
    }

    
    private static void swap(Duendes[] duendes, int i, int j){
        Duendes temp = duendes[i];
        duendes[i] = duendes[j];
        duendes[j] = temp;
    }

    public static void ordenar(Duendes[] duendes){
        int last = duendes.length - 1;
        for(int i=0; i < duendes.length-1; i++){
            int newSwap = -1;
            for(int j=0; j < last; j++){
                if(duendes[j].getIdade() == duendes[j + 1].getIdade()){
                    if(duendes[j].getNome().length() < duendes[j + 1].getNome().length()){
                        swap(duendes, j, j+1);
                    }
                }
                else if(duendes[j].getIdade() < duendes[j + 1].getIdade()){
                    swap(duendes, j, j+1);
                    newSwap = j;
                }
            }
            if(newSwap == -1){
                i = duendes.length;
            } else last = newSwap;
        }
    }

    public static void times(Duendes[] duendes){
        int n = duendes.length;
        int numTimes = n / 3;

        for (int i = 0; i < numTimes; i++) {
            System.out.println("Time " + (i + 1));
            System.out.println(duendes[i].toString());
            System.out.println(duendes[numTimes + i].toString());
            System.out.println(duendes[2 * numTimes + i].toString());
            System.out.println(); 
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if(n >= 3 && n <= 30){
            Duendes[] duendes = new Duendes[n];

            for(int i=0; i < n; i++){
                String nome = sc.next();
                int idade = sc.nextInt();
                duendes[i] = new Duendes(nome, idade);
            }
            ordenar(duendes);

            times(duendes);
        }
        sc.close();
    }
}