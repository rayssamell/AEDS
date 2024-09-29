import java.util.Scanner;

public class Duendes {
    //atributos da classe Duendes
    private String nome;
    private int idade;

    // contrutor
    public Duendes(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }
    //metodos
    public String getNome(){
        return nome;
    }
    public int getIdade(){
        return idade;
    }
    @Override
    public String toString() {
        return nome + " " + idade;
    }
    // fim metodos especificos da classe

    //metodo para trocar valores de posicao
    public static void swap(Duendes[] duendes, int i, int j){
        Duendes temp = duendes[i];
        duendes[i] = duendes[j];
        duendes[j] = temp;
    }
    //metodo para ordenar os duendes pela idade ou pelo nome(caso as idades forem as mesmas)
    public static void ordenar(Duendes[] duendes){
        int lastSwap = duendes.length - 1; 
        for(int i=0; i < duendes.length-1; i++){
            int newSwap = -1;
            for(int j=0; j < lastSwap; j++){
                //se as idades forem iguais, ordena pelo nome
                if(duendes[j].getIdade() == duendes[j+1].getIdade()){
                    if(duendes[j].getNome().length() < duendes[j+1].getNome().length()){
                        swap(duendes, j, j+1);
                        newSwap = j; 
                    }
                } else if(duendes[j].getIdade() < duendes[j+1].getIdade()){
                    swap(duendes, j, j+1);
                    newSwap = j; 
                }
            }
            if(newSwap == -1) i = duendes.length;
            else lastSwap = newSwap;
        }
    }
    //metodo para organizar os times
    public static void times(Duendes[] duendes){
        ordenar(duendes); //ordena pelas idades, ou nome

        int n = duendes.length; //guarda tamanho
        int numTimes = n / 3; // quantidade de times

        for(int i=0; i < numTimes; i++){
            System.out.println("Time " + (i + 1)); // times
            System.out.println(duendes[i].toString()); // lider
            System.out.println(duendes[numTimes + i].toString()); //entregador
            System.out.println(duendes[2 * numTimes + i].toString()); //piloto
            System.out.println(); 
        }
    
    }
    //
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if(n >= 3 && n <= 30){
            Duendes[] d = new Duendes[n];
            for(int i=0; i < n; i++){
                String nome = sc.next();
                int idade = sc.nextInt();
                d[i] = new Duendes(nome, idade);
            }
            times(d);
        }
        sc.close();
    }
}
