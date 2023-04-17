import java.util.Scanner;

public class Test{
  public static void main(String[] args){
    int n;
    Scanner sc = new Scanner(System.in);
    try {
      System.out.println("Donner un entier");
      n = sc.nextInt();
      sc.nextLine();//Pour deplacer la tete de lecture au debut
      System.out.println("La serie Harmonique de " + n + " est " +SerieHarmonic.serieHarmonic(n));
    }catch (Exception e) {
      //System.out.println("Donner un Entier");
      e.printStackTrace();
    }
    //if (n < 0)
      //System.out.println("L'entier donner est negatif le son factoriel n'exoste pas");
  }
}
