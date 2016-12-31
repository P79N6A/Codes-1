import java.util.Scanner;

public class JavaExp12 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter circle1's center x-, y-coordinates, and radius:");
		double x1 = scanner.nextDouble();
		double y1 = scanner.nextDouble();
		double r1 = scanner.nextDouble();
		
		System.out.println("Enter circle2's center x-, y-coordinates, and radius:");
		double x2 = scanner.nextDouble();
		double y2 = scanner.nextDouble();
		double r2 = scanner.nextDouble();
		
		double dx = x1 - x2, dy = y1 - y2;
		double dis = Math.sqrt(dx * dx + dy * dy);
		
		double judge = Math.abs(r1 - r2);
		if (dis > r1 + r2) System.out.println("Circle2 does not overlaps circle1");
		else if (judge <= dis && dis <= r1 + r2) System.out.println("Circle2 overlaps circle1");
		else {
			if (r1 > r2) {
				System.out.print("Circle2 is inside circle1");
			}
			else System.out.print("Circle1 is inside circle2");
		}
	}
}