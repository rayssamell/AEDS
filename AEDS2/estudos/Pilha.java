import java.util.ArrayList;

class Pilha {
    ArrayList arrayList;
    
    public Pilha(){
        arrayList = new ArrayList();
    }

    public void Inserir(int valor){
        arraList.add(valor);
    }
    public int Remover(){
        int resp = arrayList.get(0);
        arrayList.remove(0);
        return resp;
    }
    public void Mostrar(){
        for(int i = arrayList.length-1; i >= 0; i--){
            System.out.println(arrayList[i]);
        }
    }
}
