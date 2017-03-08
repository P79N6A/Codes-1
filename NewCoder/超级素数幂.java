import java.util.Scanner;
public class Main {
	
	static boolean isPrime(long n) {
		int up = (int) Math.sqrt(n);
		for (int i = 2; i <= up; ++i) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		in.close();
		
		double base = 2;
		int cur = 0, ans = -1, time = 0;
		do {
			cur = (int)Math.pow(n, 1 / base);
			if (Math.pow(cur, base) == n && isPrime(cur)) {
				time = (int)base;
				ans = cur;
				break;
			}
			++base;
		} while (cur > 1);
		
		if (ans != -1) {
			System.out.println(ans + " " + time);
		}
		else {
			System.out.println("No");
		}
	}
}