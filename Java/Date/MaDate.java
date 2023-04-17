import java.util.Calendar;

public class MaDate {
	private int jour, mois, an;
	
	public MaDate(){
		Calendar now = Calendar.getInstance();
		this.jour = now.get(Calendar.DAY_OF_MONTH);
		this.mois = now.get(Calendar.MONTH) + 1;
		this.an = now.get(Calendar.YEAR);
	}
	public MaDate(int jour,int mois,int an){
		this.jour = jour;
		this.mois = mois;
		this.an = an;
		}
	public String toString(){
		return jour + "/"+ mois + "/"+ an;
	}
	public boolean egale (MaDate autre){
	return this.jour == autre.jour && 
		   this.mois == autre.mois &&
		   this.an == autre.an;
	}
	
	public boolean equals(Object o){
		if(! (o instanceof MaDate))
			return false;
		MaDate autre = (MaDate) o;
		return this.jour == autre.jour && 
			   this.mois == autre.mois &&
			   this.an == an ; 
				
	}
	
	public int compare (MaDate datecmp){
		if(this.egale(datecmp))
			return 0;
		else{
			if(this.an > datecmp.an)
				return  1;
			else
				if(this.an == datecmp.an && this.mois>datecmp.mois)
					return 1;
				else
					if(this.an == datecmp.an && this.mois == datecmp.mois && this.jour>datecmp.jour)
						return 1;
					else 
						return -1;}	
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MaDate date = new MaDate();
		MaDate date1 = new MaDate(10,12,2021);
		System.out.println("La date du jour est "+ date);
		System.out.println("Egalite 1  " + date.egale(date1));
		//System.out.println("Egalite 2 " + date.egale(date));
		System.out.println("Egalite 2 " + date.equals(date));
		System.out.println("compare " + date.compare(date1));
	}

}
