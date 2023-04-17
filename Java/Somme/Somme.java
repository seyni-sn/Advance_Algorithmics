import java.util.Scanner;

public class Somme {
	double a, b;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		boolean bonnesaisie = false;
		
		Scanner scan = new Scanner(System.in);
		do{
			try 
			{	bonnesaisie = false;
				System.out.println("donner a");
				double a = scan.nextDouble();
				
				System.out.println("donner b");
				double b = scan.nextDouble();
				
				double resultat = a + b;
				System.out.println("la somme est = " + resultat);
			} catch (Exception ex) {
				
				
				System.out.println("Mauvaise Saisie");
				bonnesaisie = true;
			}
			
		}while(bonnesaisie);
	}

}
