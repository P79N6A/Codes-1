import java.util.Scanner;

public class JavaExp11 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Loan amount: ");
		double tol = scanner.nextDouble();
		System.out.print("Number of Years: ");
		int year = scanner.nextInt();
		
		System.out.println("Interest Rate       Monthly Payment         Total Payment");
		for (double i = 0.05; i <= 0.08; i += 0.00125) {
			double mi = i / 12;
			double month = (tol * mi) / (1.0 - 1 / Math.pow(1.0 + mi, year * 12));
			double tolpay = month * 12 * year;
			System.out.printf("  %.3f%%               %.2f                     %.2f\n", i * 100, month, tolpay);
		}
	}
}