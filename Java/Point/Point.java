public class Point {
  private int x, y;
  public Point(int x, int y){ this.x = x; this.y = y; }
  
  public String toString(){
   return "Point[" + x + ", " + y + "]";
  }
  
  public static void permuter (Point p1, Point p2){
    Point temp = p1; p1 = p2; p2 = temp;
  }
  
  public static void modifierCoordonnees(Point p1, int x, int y){
    p1.x = x; p1.y = y;
  }
  
  public static void main (String args[]){
    Point p1 = new Point(0, 0); Point p2 = new Point(5, 20);
    System.out.println(p1);
    System.out.println(p2);
    Point.modifierCoordonnees(p1, 12, 12);
    System.out.println("Apres modif p1");
    System.out.println(p1);
    Point.permuter(p1, p2);
    System.out.println("Apres permutation");
    System.out.println(p1);
    System.out.println(p2);
  }
}
