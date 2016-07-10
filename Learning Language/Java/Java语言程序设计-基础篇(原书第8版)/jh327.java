import java.util.*;

public class jh327 {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		System.out.print("Enter a point's x- and y- coordinates: ");
		double x = cin.nextDouble(), y = cin.nextDouble();
		if (x >= 0 && y >= 0 && -0.5 * x + 100 >= y) {
			System.out.println("The point is in the triangle.");
		}
		else {
			System.out.println("The point is not in the triangle.");
		}
	}
}