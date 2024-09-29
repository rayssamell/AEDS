import java.util.Scanner;

public class Relogio {
    // metodo para calcular horas de sono
    public static void despertador(int h1, int m1, int h2, int m2){
        //tranforma hora em minuto e soma com os minutos
        int hora1 = (h1*60)+m1; 
        int hora2 = (h2*60)+m2;

        int horario = 0; //variavel para resultado

        if(hora2 < hora1){
            hora2 += 24 * 60;
        } 
        horario = hora2 - hora1;

        System.out.println(horario);

    }
    //metodo principal
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // ler dados
        int h1 = sc.nextInt();
        int m1 = sc.nextInt();
        int h2 = sc.nextInt();
        int m2 = sc.nextInt();

        //enquanto todos forem diferente de 0
        while(!(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)){
            // chamar funcao para calcular as horas de sono
            despertador(h1,m1,h2,m2);
            // proxima leitura enquanto forem diferentes de 0
            h1 = sc.nextInt();
            m1= sc.nextInt();
            h2 = sc.nextInt();
            m2 = sc.nextInt();
        }
        sc.close();
    }
}