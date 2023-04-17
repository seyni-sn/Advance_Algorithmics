import java.lang.*;
public class Test {
	private double x;
	private int p;
	String chaine;
	public Test(int p,double x) {
		this.x = x;
		this.p = p;
		
	}
	public Test(String s) {
		this.chaine = s;
		
	}
	public double puissance(int p,double x){
		
		if(p  ==0 )return 1;
		else
			if(p ==1)
				return x;
			else return x*puissance(p-1,x);		
	}
	public int compare(String s2){
		int n1 = this.chaine.length(),n2 = s2.length();
		int min = 0,i = 0,j = 0;
		if(n1<n2){
			min = n1;
			j = -1;
		}
		else{
			min = n2;
			j = 1;
		}
		
		while(i< min){
			if(this.chaine.charAt(i) == s2.charAt(i))
				i++;
			else
				if(i<min){
					if(this.chaine.charAt(i)<s2.charAt(i))
						return -1;
					else
						if(this.chaine.charAt(i)>s2.charAt(i))
							return 1;
						else return 0;
				}	
		}return  j;
	}
	

	

	public static void main(String[] args) {
		Test P = new Test(2,4.0);
		Test s1 = new Test("test");
		String s2 = new String("abc");
		System.out.println("la puissance est "+ P.puissance(2,4.0));
		System.out.println("resultat cmp est "+ s1.compare(s2));


		
		
	}

}
