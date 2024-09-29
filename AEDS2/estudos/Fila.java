import java.util.ArrayList;

class Fila {
  ArrayList<Integer> arrayList;

  public Fila() {
    arrayList = new ArrayList<>();
  }

  public void Inserir(int valor){
    arrayList.add(valor);
  }
  public int Remover(){
    int resp = arrayList.get(0);
    arrayList.remove(0);
    return resp;
  }
  public void Mostrar(){
    for (int i : arrayList) {
      System.out.println(i);
    }
  }
  public static void main(String[] args){
    Fila fila = new Fila();

    for(int i = 0; i < 10; i++){
        fila.Inserir(i);
    }

    fila.Inserir(10);
    fila.Inserir(15);
    System.out.println(fila.Remover());
    fila.Inserir(5);
    System.out.println("------Mostrar-------");
    fila.Mostrar();
  }
}

