public class Factoriel{
  public Factoriel(String[] args){

  }
  public static int factoriel(int n) throw ExceptionEntierNegatif{
    if (n == 0)
      return 1;
    else if (n < 0)
      throw new ExceptionEntierNegatif();
    else
      return n*factoriel(n-1);
  }
}
