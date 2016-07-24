import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
    	Scanner cin = new Scanner(System.in);
    	int n = cin.nextInt();
    	BigInteger p[] = new BigInteger[300];
    	BigInteger num[] = new BigInteger[300];
    	BigInteger ans = BigInteger.ONE;
    	num[0] = BigInteger.ZERO;
    	for (int i = 1; i < 300; ++i) num[i] = num[i - 1].add(BigInteger.ONE);
    	int cnt = 0;
    	for (int i = 2; i <= 300; ++i) {
    		boolean flag = true;
    		for (int j = 2; j * j <= i; ++j) {
    			if (i % j == 0) {
    				flag = false;
    				break;
    			}
    		}
    		if (flag) {
    			p[cnt++] = num[i];
    		}
    	}
    	for (int i = 0; i < n; ++i) ans = ans.multiply(p[i]);
    	if (n == 2) System.out.println(-1);
    	else {
    		for (int i = 0; i < n; ++i) {
    			System.out.println(ans.divide(p[i]));
    		}
    	}
    	cin.close();
    }
}
