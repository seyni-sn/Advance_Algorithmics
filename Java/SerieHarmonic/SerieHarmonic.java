public class SerieHarmonic{

  public SerieHarmonic(){

  }
  public static double serieHarmonic(int n){
    int result = 0;
    if (n == 0 || n == 1)
      return n;
    else{
      for (int i = 1; i <= n ; i++ ) {
        result += (double)1/i;
      }
      return result;
    }
  }
}
