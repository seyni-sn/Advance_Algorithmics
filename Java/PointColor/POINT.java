public class POINT {
	private int x;
	private int y;

	public POINT(int abs, int ord) {
		x = abs;
		y = ord;
	}
	public void afficher(){
		System.out.println("Point[" + x + "," + y + "]");
	}
	public String toString(){
		return "Point[" + x + "," + y + "]";
		
	}
	public static void main(String[] args) {
		POINT p1 = new POINT(10,10);
		POINT p2 = new POINT(10,5);
		p1.afficher();
		p2.afficher();
		PointColor pc = new PointColor(1,1, "vermenthe");
		pc.afficher();
		System.out.println(p1.toString());

	}
}


