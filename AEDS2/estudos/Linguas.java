import java.util.Scanner;

public class Linguas {
    private static class Idioma {
        private String lingua;
        private String escrita;

        public Idioma(String lingua, String escrita) {
            this.lingua = lingua;
            this.escrita = escrita;
        }

        public String getLingua() {
            return lingua;
        }

        public String getEscrita() {
            return escrita;
        }
    }

    public static void imprimir(String nome, String lingua, Idioma[] idioma) {
        for (int i = 0; i < idioma.length; i++) {
            if (lingua.equals(idioma[i].getLingua())) {
                System.out.println(nome);
                System.out.println(idioma[i].getEscrita());
                System.out.println();
                i = idioma.length;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); 

        if (n > 1 && n < 100) {
            Idioma[] idioma = new Idioma[n];
            for (int i = 0; i <n; i++) {
                String lingua = sc.nextLine();
                String escrita = sc.nextLine();
                idioma[i] = new Idioma(lingua, escrita);
            }

            int m = sc.nextInt();
            sc.nextLine();

            if (m >= 1 && m < 100) {
                for (int i = 0; i < m; i++) {
                    String nome = sc.nextLine();
                    String lingua = sc.nextLine();
                    imprimir(nome, lingua, idioma);
                }
            }
        }
        sc.close();
    }
}
